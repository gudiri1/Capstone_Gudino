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

  //std::future<bool> ftr = std::async(&FlyingBlock::PropelBlock, this->fblock);
  //this->blockFlies = ftr.get();

}

bool FlyingBlock::PropelBlock()
{
    
    //_pos_x = initPos_x ;
    //_pos_y = initPos_y - 20;

    _pos_y = _pos_y - 20;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    

    return 1;
}