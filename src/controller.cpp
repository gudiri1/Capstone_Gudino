#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "GameObject.h"

void Controller::HandleInput(bool &running, Mason &mason) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
                
        case SDLK_KP_4:
          mason.SetState(GameObject::State::moveToLeft); 
          break;

        case SDLK_KP_6:
          mason.SetState(GameObject::State::moveToRight); 
          break;

        case SDLK_KP_8:
          mason.blockFlies = 1;
          mason.fblock.SetPos_x(mason.GetPos_x());
          mason.fblock.SetPos_y(mason.GetPos_y());
          mason.SetState(GameObject::State::fire); 
          break;
        
      }
    }
  }
}