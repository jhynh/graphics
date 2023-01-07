#pragma once
#include "components.hpp"
#include "../Vector2D.hpp"
//each component type we create can make use of the Component functions
struct TransformComponent : public Component{

    Vector2D position;
    Vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;

    
    TransformComponent()
    {
        position.Zero();
    }

    TransformComponent(int sc)
    {
        position.Zero();
        scale = sc; 
    }

    //possible useless function
    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int h, int w, int sc){
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }
    
    
    void init() override{
        velocity.Zero();
    }

    void update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

    }


};