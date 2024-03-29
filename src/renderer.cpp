#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Mason Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}


Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}


void Renderer::Render(Mason mason, Wall wall) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render mason
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0xCC, 0xFF);
  block.x = mason.GetPos_x();
  block.y = mason.GetPos_y();
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render FlyingBlock
  if (mason.blockFlies == 1){
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0xCC, 0xFF);
  block.x = mason.fblock.GetPos_x();
  block.y = mason.fblock.GetPos_y();
  SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render Wall
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0xCC, 0xFF);
  int x_pos = 6 * 20;
  int y_pos = 15 * 20;
  for (auto point : wall.presence) {
    if (point == 1) {
      block.x = x_pos;
      block.y = y_pos;
      SDL_RenderFillRect(sdl_renderer, &block);
    }
    x_pos += 20;
  }
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
