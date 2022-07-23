#include "mason.h"
#include <cmath>
#include <iostream>

void Mason::Update(bool &DirFlag) 
{

  switch (this->state) {
    case GameObject::State::moveToLeft :
      _pos_x -=20;
       state = GameObject::State::idle;
      break;

    case GameObject::State::moveToRight :
      _pos_x +=20;
       state = GameObject::State::idle;
      break;

    case GameObject::State::fire:
       DirFlag = true;
       state = GameObject::State::idle;
      break;
  }

}

void FlyingBlock::Update(Mason &mason)
{
    _pos_x = mason.GetPos_x();
    _pos_y = mason.GetPos_y() - 20;
}