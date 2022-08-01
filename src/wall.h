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

Wall(){
    this->SetNewWall();
}

std::vector<SDL_Point> bricks;

void Update();

void SetNewWall();

std::vector<bool> presence = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};

private:

 
};



#endif