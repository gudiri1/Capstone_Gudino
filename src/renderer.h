#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "mason.h"
#include "wall.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Mason mason, Wall wall);
  void UpdateWindowTitle(int score, int fps);

  
 private:
  SDL_Window *sdl_window;          // holds all info about the window 
  SDL_Renderer *sdl_renderer;      // tied to SdlWindow. Handles the rendering

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif