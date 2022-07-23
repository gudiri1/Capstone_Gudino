#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "mason.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Mason &mason) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif