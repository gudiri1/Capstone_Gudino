#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
// #include "mason.h"
#include <memory>
#include "wall.h"



class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  

 private:
  Snake snake;
  SDL_Point food;

  Mason mason;

  Wall wall;

  //FlyingBlock fblock;

    
  //std::shared_ptr<Wall> wall = std::make_shared<Wall>();;

  SDL_Point stone;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif