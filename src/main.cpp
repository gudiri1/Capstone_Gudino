#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <thread>
#include "block.h"


  void threadFunction(Renderer &renderer){
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      Block blocky;
      blocky.foo(renderer);
      
  }

int main() {
  constexpr std::size_t kFramesPerSecond{10};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //threadFunction();
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);

  Controller controller;
  Game game(kGridWidth, kGridHeight);

  game.Run(controller, renderer, kMsPerFrame);
  //std::thread t(threadFunction, std::ref(renderer));

  //t.join();
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  //t.join(); 

  return 0;
}