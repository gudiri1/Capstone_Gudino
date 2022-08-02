#include "wall.h"
#include <cmath>
#include <iostream>
#include <random>
#include <vector>


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