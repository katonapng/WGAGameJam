#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <string>

class Enemy;

class Game {
public:
  using SFMLWindow = int;

  Game();

  void Draw();
  
  const Player &GetPlayer();

  const Enemy GetEnemy();

  SFMLWindow& GetWindow();

private:
  Player player_;
  Enemy enemy_;
  std::string word_;
};

#endif // GAME_HPP
