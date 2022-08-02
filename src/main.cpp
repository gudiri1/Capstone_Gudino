#include <iostream>
#include "controller.h"
//#include "GameObject.h"
#include "game.h"
#include "renderer.h"
#include <thread>
#include "mason.h"
#include "wall.h"


int main() {
  constexpr std::size_t kFramesPerSecond{10};    // constexpr: constant and known during compilation
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  std::shared_ptr<Mortar> mortar1 = std::make_shared<Mortar>();

  Game game(kGridWidth, kGridHeight, mortar1);

  game.Run(controller, renderer, kMsPerFrame, mortar1);

  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
 
  return 0;
}