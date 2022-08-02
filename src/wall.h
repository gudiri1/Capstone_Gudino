#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include <vector>
#include "SDL.h"

class Wall : public GameObject
{
public:

    Wall(){
        this->SetNewWall();
    }

    void SetNewWall();

    std::vector<bool> presence = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};

private:
 
};



#endif