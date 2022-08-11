#ifndef MASON_H
#define MASON_H

#include "SDL.h"
#include "GameObject.h"
#include "wall.h"
#include <future>

class Mason;

class FlyingBlock : public GameObject
{
public:

  int initPos_x;
  int initPos_y;

  bool PropelBlock(Mason &mason, Wall &wall);

  int countScore{0};

private:

};


class Mason : public GameObject
{
public:

  Mason() {
    _pos_x = 15 * 20; 
    _pos_y = 29 * 20;

  }    

  bool blockFlies;

  void Update();

  FlyingBlock fblock;

private:


};



#endif