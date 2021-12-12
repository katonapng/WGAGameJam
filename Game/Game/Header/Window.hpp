#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Game.hpp"
#include "DrawMenu.hpp"
#include <SFML/Graphics.hpp>

class Window {
public:
  using Menu = int;

  // window creation and intialization
  Window();

  // start rendering and events processing
  void StartLoop();

  char GetKey(sf::Event);

private:
  sf::RenderWindow window_;
  Game game_;
  DrawMenu menu_;
  bool is_menu_opened_;

  static constexpr std::size_t kFramerateLimit{60};
};

#endif // !WINDOW_HPP
