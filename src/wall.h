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

    ~Wall(){
        //Wall(const &Wall&) = delete;
    }

    void SetNewWall();

    std::vector<bool> presence; // = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};

    std::mutex *_mutex;
    int a;

private:

    //std::mutex _mutex;
 
};



#endif