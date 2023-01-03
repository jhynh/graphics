#pragma once
#include "components.hpp"
#include "Vector2D.hpp"
//each component type we create can make use of the Component functions
struct TransformComponent : public Component{

    Vector2D position;

    TransformComponent()
    {
        position.x = 0;
        position.y = 0;
    }

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    void update() override{
        
    }


};