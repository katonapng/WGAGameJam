#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class Enemy;

class Game {
public:
  

  Game();

  void Draw();
  
  const Player &GetPlayer();

  const Enemy GetEnemy();

  sf::RenderWindow& GetWindow();

private:
  Player player_;
  Enemy enemy_;
  std::string word_;
};

#endif // GAME_HPP
