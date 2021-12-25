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
#include <fstream>

class Game {
public:
  Game(sf::RenderWindow &sf_window);

  void Draw();

  Player &GetPlayer();

  Enemy &GetEnemy();

  sf::RenderWindow &GetWindow();

  void CreateNewEnemy();

  void EndRound();
  bool EndGame() {
    return player_->End();
  }
  inline void GetKeyInput(char key) { player_->InputSymbol(key); }
  void NewGame(bool a);
  void CreateNewPlayer();
  bool PlayerIsDead();
  void DrawScore(sf::RenderWindow& sf_window);

  void WriteScore();
private:
  sf::Clock clock;
  sf::Time start_round_time_= sf::milliseconds(0);
  Player *player_;
  Enemy *enemy_;
  std::string word_;

  sf::Texture background_;
  sf::Sprite background_sprite_;

  sf::RenderWindow &sf_window_;

  int num_ = 1;
  int score_ = 0;
  double enemyTime_ = 15000;
  sf::Font font_;
  float font_size_=100;

  std::ofstream fout_;
  std::random_device random_;
  
};

#endif // GAME_HPP
