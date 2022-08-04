#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include <vector>
#include "SDL.h"
#include <mutex>

class Wall : public GameObject
{
public:

    Wall(){
        _mutex = new std::mutex();
    }

    void SetNewWall();

    std::vector<bool> presence; // = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};

    std::mutex *_mutex;

private:
    
 
};



#endif