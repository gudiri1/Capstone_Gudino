#ifndef MASON_H
#define MASON_H

#include "SDL.h"
#include "GameObject.h"
#include <future>

class Mason;

class FlyingBlock : public GameObject
{
public:

  FlyingBlock() {
    //_pos_x = 15 * 20; 
    //_pos_y = 29 * 20;

  }    

  ~FlyingBlock(){};

  //SDL_Point InitPos;

  int initPos_x;
  int initPos_y;


  bool PropelBlock();

private:


};


class Mason : public GameObject
{
public:

  Mason() {
    _pos_x = 15 * 20; 
    _pos_y = 29 * 20;

 }    

~Mason(){};

bool blockFlies;


void Update(bool &DirFlag);

FlyingBlock fblock;

private:

// std::future<bool> mftr;


};



#endif