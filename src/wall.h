#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include <vector>
#include "SDL.h"
#include <mutex>

class Wall : public GameObject
{
public:

    void SetNewWall();

    std::vector<bool> presence; 

private:

};



#endif