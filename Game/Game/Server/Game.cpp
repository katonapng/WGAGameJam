#include "../Header/Game.hpp"

namespace fs = std::filesystem;

Game::Game(sf::RenderWindow &sf_window)
    : sf_window_{sf_window}, player_{}, enemy_{new EnemyBomb} {
  auto path{fs::current_path()
             /*   .append("WGAGameJam")
                .append("Game")
                .append("Game")*/
                .append("GameImages")
                .append("background.png")};
  if (!background_.loadFromFile(path.string())) {
    exit(1);
  }

  float width = sf_window_.getSize().x;
  float height = sf_window_.getSize().y;

  sf::Vector2u backgroundSize = background_.getSize();
  float scaleX = (float)width / backgroundSize.x;
  float scaleY = (float)height / backgroundSize.y;

  background_sprite_.setPosition(0, 0);
  background_sprite_.setTexture(background_);
  background_sprite_.setScale(scaleX, scaleY);

  CreateNewEnemy();
}

void Game::Draw() {
  sf_window_.draw(background_sprite_);
  if (!enemy_->IsDead()) {
    auto current_time{std::chrono::high_resolution_clock::now()};

    auto time{std::chrono::duration<double, std::milli>(current_time -
                                                        start_round_time_)
                  .count()};

    /*player_->Draw(*this, time);*/
    enemy_->Draw(*this, time);
  } else {
    delete enemy_;
    CreateNewEnemy();
    start_round_time_ = std::chrono::high_resolution_clock::now();
  } 
}

const Player &Game::GetPlayer() { return *player_; }

const Enemy &Game::GetEnemy() { return *enemy_; }

sf::RenderWindow &Game::GetWindow() { return sf_window_; }

void Game::CreateNewEnemy() {}
void Game::GetKeyInput(char key) {};
