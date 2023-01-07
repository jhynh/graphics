#pragma once
#include <SDL2/SDL.h>

//avoid circular dependencies
class ColliderComponent;

class Collision{
public:
    //access aligned bounding box
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);

    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};