#include "../Header/Game.hpp"

namespace fs = std::filesystem;

Game::Game(sf::RenderWindow &sf_window)
    : sf_window_{sf_window}, player_{new Player}, enemy_{new EnemyTNT} {
  auto path{fs::current_path()
                /*.append("WGAGameJam")
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
  clock.restart();
  CreateNewEnemy();
}

void Game::Draw() {
  sf_window_.draw(background_sprite_);
  if (player_->GetState()) {//todo
    sf::Time current_time{clock.getElapsedTime()};
    
    sf::Time time= sf::milliseconds(current_time.asMilliseconds()-start_round_time_.asMilliseconds());
    
    if (enemy_->IsDead()&&(num_<4)) {
      player_->Damage();
      num_++;
    }
    player_->Draw(*this, time.asMilliseconds());
    enemy_->Draw(*this, time.asMilliseconds());
    DrawScore(sf_window_);
    
  } else { 

    EndRound();
    CreateNewEnemy();
    start_round_time_ = clock.getElapsedTime();
    
    std::cout << "new enemy\n";
  } 
 
}

Player &Game::GetPlayer() { return *player_; }

Enemy &Game::GetEnemy() { return *enemy_; }

sf::RenderWindow &Game::GetWindow() { return sf_window_; }

void Game::CreateNewEnemy() {
  if (enemyTime_ > 2500) {
    enemyTime_ -= 500;
  }
  Enemy *tmp = enemy_;
  delete tmp;
  if(random_()%2){
    enemy_ = new EnemyTNT;
  }
  else {
    enemy_ = new EnemyBomb;
  }
  enemy_->ChangeTime(enemyTime_);
}
void Game::CreateNewPlayer() {
  Player* tmp = player_;
  delete tmp;
  player_ = new Player;
}

void Game::EndRound() {
  num_ = 1; //todo
  sf::Time current_time{ clock.getElapsedTime() };
  sf::Time time = sf::milliseconds(current_time.asMilliseconds() - start_round_time_.asMilliseconds());
  if (!player_->GetState()) {
    score_ += std::abs((enemy_->GetTime() - time.asMilliseconds()) / enemy_->GetTime()) * 10;
  }
  clock.restart();
}

void Game::NewGame(bool a) {
  if (a) {
    score_ = 0;
    enemyTime_ = 15000;
    this->EndRound();
    this->CreateNewPlayer();
    this->CreateNewEnemy();
  }
}
bool Game::PlayerIsDead() {
  return player_->IsDead();
}

void Game::DrawScore(sf::RenderWindow& sf_window) {
  std::size_t begin_pos{ static_cast<std::size_t>(sf_window.getSize().x * 0.45f) };
  std::size_t pos_y{ static_cast<std::size_t>(sf_window.getSize().y * 0.0f) };

  sf::Text text;
  if (!font_.loadFromFile("WordResources/font.ttf")) {
    std::exit(3);
  }
  text.setFont(font_);
  text.setCharacterSize(font_size_);
  std::string str{ "score: " };
  str.append(std::to_string(score_));
  font_size_ = sf_window.getSize().y * 0.6f / str.size();
    text.setFillColor(sf::Color::Black);

    text.setString(str);
    text.setPosition(begin_pos + font_size_ * str.size(), pos_y);
    sf_window.draw(text);
  
};

void Game::WriteScore() {
  fout_.open("file.txt");
  std::string str{ "score: " };
  str.append(std::to_string(score_));
  fout_ << str<<std::endl;
  fout_.close();
}