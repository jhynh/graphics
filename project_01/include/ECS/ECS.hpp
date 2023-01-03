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

//componentID is standard sizeT
using ComponentID = std::size_t;

//acts like a headerfile, puts function code where we include
inline ComponentID getComponentTypeID(){
    static ComponentID lastID = 0;
    return lastID++;
}

//create template function to get id
//when pass component already have we assign one
//for each we create, give id incremeneted

//inline prevents overhead from function return address calling 
template <typename T> inline ComponentID getComponentTypeID() noexcept{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;             //bring base class method/var into current class scope
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
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;

public:
    
    void update(){
        for(auto& c : components) c->update();
    }

    void draw(){
        for(auto& c : components) c->draw();
    }

    bool isActive()const {return active;}
    void destroy() {active = false;}

    template<typename T> bool hasComponent() const{
        //has it got componenet? -> true or false
        return componentBitSet[getComponentTypeID<T>];
    }

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
        componentBitSet[getComponentTypeID<T>()] = true;

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

    std::vector<std::unique_ptr<Entity>> entities;

public:

    void update(){
        for(auto& e : entities) e->update();
    }

    void draw(){
        for(auto& e : entities) e->draw();
    }

    void refresh(){
        //removes entities if not active
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
            [](const std::unique_ptr<Entity> &mEntity)
            {
                return !mEntity->isActive();
            }),
            std::end(entities));
    }

    Entity& addEntity(){
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{e};

        entities.emplace_back(std::move(uPtr));
    
        return *e;
    }

};