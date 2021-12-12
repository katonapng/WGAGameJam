#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Game.hpp"

class Window {
public:
  // window creation and intialization
  Window();

  // start rendering and events processing
  void StartLoop();

private:
  Game game_;
};

#endif // !WINDOW_HPP
