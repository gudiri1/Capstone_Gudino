#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

#include <vector>
#include "SDL.h"


struct Brick : public GameObject
{
    int color;
    bool presence;
};

class Wall : public GameObject
{

public:

std::vector<SDL_Point> bricks;

void Update();

std::vector<bool> presence = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

private:

 
};



#endif