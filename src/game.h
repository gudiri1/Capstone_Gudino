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
#include "mortar.h"



class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, std::shared_ptr<Mortar> mortar);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration, std::shared_ptr<Mortar> mortar );
  int GetScore() const;
  int GetSize() const;

  

 private:
  Snake snake;
  SDL_Point food;
  Mason mason;
  Wall wall;

  //std::shared_ptr<Mortar> mortar;

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