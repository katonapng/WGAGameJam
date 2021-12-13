#ifndef GAME_HPP
#define GAME_HPP

#include "Enemy.hpp"
#include "Player.hpp"
#include "EnemyBomd.hpp"
#include "EnemyTNT.hpp"
#include <SFML/Graphics.hpp>
#include <filesystem>

#include <chrono>
#include <string>

class Game {
public:
  Game(sf::RenderWindow &sf_window);

  void Draw();

  Player &GetPlayer();

  Enemy &GetEnemy();

  sf::RenderWindow &GetWindow();

  void CreateNewEnemy();

  void EndRound();

  inline void GetKeyInput(char key) { player_->InputSymbol(key); }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_round_time_;
  Player *player_;
  Enemy *enemy_;
  std::string word_;

  sf::Texture background_;
  sf::Sprite background_sprite_;

  sf::RenderWindow &sf_window_;
};

#endif // GAME_HPP