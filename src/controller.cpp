#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "GameObject.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, Mason &mason) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        
        case SDLK_KP_4:
          //mason.state = GameObject::State::moveToLeft;
          mason.SetState(GameObject::State::moveToLeft); 
          break;

        case SDLK_KP_6:
          mason.SetState(GameObject::State::moveToRight); 
          break;

        case SDLK_KP_8:
          mason.SetState(GameObject::State::fire); 
          break;
        
      }
    }
  }
}