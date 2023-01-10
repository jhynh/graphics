#pragma once

#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
#include<bitset>
#include<array>

//forward statements
class Component;
class Entity;
class Manager;

//componentID is standard sizeT
using ComponentID = std::size_t;
using Group  = std::size_t;

//acts like a headerfile, puts function code where we include
inline ComponentID getNewComponentTypeID(){
    static ComponentID lastID = 0u;
    return lastID++;
}

//create template function to get id
//when pass component already have we assign one
//for each we create, give id incremeneted

//inline prevents overhead from function return address calling 
template <typename T> inline ComponentID getComponentTypeID() noexcept{
    static_assert(std::is_base_of<Component, T>::value,"");
    static ComponentID typeID = getNewComponentTypeID();
    return typeID;
}

//thresholds
constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;                           //groups/render layers/collision layers, each entity can be a member of multiple groups


using ComponentBitSet = std::bitset<maxComponents>;             //bring base class method/var into current class scope
using GroupBitSet = std::bitset<maxGroups>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component{

public:
    Entity* entity;

    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}

    virtual ~Component(){}

};

class Entity{
private:
    Manager& manager;
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    GroupBitSet groupBitset;

public:
    //mManager = member manager
    Entity(Manager& mManager) : manager(mManager){}

    void update(){
        for(auto& c : components) c->update();
    }

    void draw(){
        for(auto& c : components) c->draw();
    }

    bool isActive()const {return active;}
    void destroy() {active = false;}

    //return T/F depending if 0 or 1
    bool hasGroup(Group mGroup){
        return groupBitset[mGroup];
    }

    void addGroup(Group mGroup);
    void delGroup(Group mGroup){
        groupBitset[mGroup] = false;
    }

    template<typename T> bool hasComponent() const{
        //has it got componenet? -> true or false
        return componentBitSet[getComponentTypeID<T>()];
    }

//template function 
    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&...mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        
        //deep copy
        components.emplace_back(std::move(uPtr));

        //when we add position componenet, it is always placed in same position in array
        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;            //done so by having a second "array"

        c->init();
        return *c;
    }

    template<typename T> T& getComponent() const{
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

    //example of in use component system:
    //gameobject.getComponent<positionComponent>().setXpos(25);
};
class Manager{
private:
    //vector to entities
    std::vector<std::unique_ptr<Entity>> entities;
    //array[32] with a vector of entity ptrs
    std::array<std::vector<Entity*>, maxGroups> groupedEntities;

public:

    void update(){
        for(auto& e : entities) e->update();
    }

    void draw(){
        for(auto& e : entities) e->draw();
    }

    void refresh(){

        for(auto i(0u); i < maxGroups; ++i){
            auto& v(groupedEntities[i]);
            v.erase(
                std::remove_if(std::begin(v), std::end(v),
                [i](Entity* mEntity)
                {
                    return !mEntity->isActive() || !mEntity->hasGroup(i);
                }),
                    std::end(v));
        }

        //removes entities if not active
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
            [](const std::unique_ptr<Entity> &mEntity)
            {
                return !mEntity->isActive();
            }),
            std::end(entities));
    }

    void AddToGroup(Entity* mEntity, Group mGroup){
        groupedEntities[mGroup].emplace_back(mEntity);
    }

    std::vector<Entity*>& getGroup(Group mGroup){
        return groupedEntities[mGroup];
    }

    Entity& addEntity(){
        Entity* e = new Entity(*this);
        std::unique_ptr<Entity> uPtr{e};

        entities.emplace_back(std::move(uPtr));
    
        return *e;
    }

};