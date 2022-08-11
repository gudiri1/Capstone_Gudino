#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include <memory>
#include "wall.h"



class Game {
 public:
  
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

  int GetScore() const;
  void SetScore(int s);
  
 private:

  Mason mason;

  Wall wall;

  int score{0};

};

#endif