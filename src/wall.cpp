#include "wall.h"
#include <cmath>
#include <iostream>
#include <random>
#include <vector>



void Wall::Update() {
  // Add previous head location to vector

  //SDL_Point brick{11, 16};
  //bricks.push_back(brick);

  
  //  body.erase(body.begin());
  

  // 
  for (auto const &i : bricks) {
    //if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      //alive = false;
   // }
  }

}


void Wall::SetNewWall(){
  std::random_device rd; // obtain a random number 
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution <> distr(0, 1); // define the range

  presence = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}; // setting the extremes

  // filling the wall up" with random values
  for(int n=1; n<19; ++n){
  this->presence.at(n)=distr(gen);
  }

}