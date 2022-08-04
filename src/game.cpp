#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <future>
#include <algorithm>


Game::Game(std::size_t grid_width, std::size_t grid_height)
    : engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
}

bool Game::ReadWall(std::vector<bool> v){
  return (std::count(v.begin(), v.end(), 0));
}

void Game::SetScore(int s){
  score = s;
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  wall.presence = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};
  wall.SetNewWall();
  

  mason.blockFlies = 0;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, mason);

    std::thread t2(&Mason::Update, &mason);

    std::thread t3(&FlyingBlock::PropelBlock, &mason.fblock, std::ref(mason), std::ref(wall));
    
    bool a = ReadWall(wall.presence);
    
    renderer.Render(mason, wall);
    

    t2.join();
    t3.join();

    SetScore(mason.fblock.countScore);

    

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
     
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

int Game::GetScore() const { return score; }
