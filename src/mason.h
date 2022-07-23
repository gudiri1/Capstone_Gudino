#ifndef MASON_H
#define MASON_H

#include "GameObject.h"

class Mason;

class FlyingBlock : public GameObject
{
public:

  FlyingBlock() {
    _pos_x = 15 * 20; 
    _pos_y = 29 * 20;

  }    

  ~FlyingBlock(){};


  void Update(Mason &mason);

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


void Update(bool &DirFlag);

FlyingBlock fblock;

private:


};



#endif