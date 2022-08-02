#include "mason.h"
#include "wall.h"
#include <cmath>
#include <iostream>

#define MAX_NUMBER_OF_BRICKS    20

void Mason::Update() 
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
       state = GameObject::State::idle;
      break;
  }

}

bool FlyingBlock::PropelBlock(Mason &mason, Wall &wall)
{

  int totalPresence;

  for(std::vector<bool>::iterator i = wall.presence.begin(); i != wall.presence.end(); ++i)
    totalPresence += *i;

  if (totalPresence == MAX_NUMBER_OF_BRICKS){
    wall.SetNewWall();
    countScore++;
  }

  _pos_y = _pos_y - 20;

  int index = (_pos_x - 120/*initial wall point*/)/20; 

  if (_pos_y == 300){
    mason.blockFlies = 0;
    wall.presence[index] = 1;
  }
  
  std::this_thread::sleep_for(std::chrono::milliseconds(50));

  totalPresence = 0;

  return 1;
}