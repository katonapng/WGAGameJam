#include "../Header/Player.hpp"
#include "../Header/Game.hpp"

namespace fs = std::filesystem;

Player::Player()
    : GameObject{}, word_gen_{GetWordResources("words.txt")},
      word_drawer_{word_gen_.Generate(), GetWordResources("font.ttf"), 1080} {
  auto path{fs::current_path()
                .append("WGAGameJam")
                .append("Game")
                .append("Game")
                .append("Animation")
                .append("Player")};

  auto death_path{path};
  death_path.append("Death").append("new");
  death_animation_.resize(kDeathFramesNum);
  for (std::size_t i{}; i < kDeathFramesNum; ++i) {
    auto tmp{death_path};
    death_animation_[i].loadFromFile(tmp.append(std::to_string(i)).string() +
                                     ".png");
  }

  auto fire_path{path};
  fire_path.append("Fire").append("new");
  fire_animation_.resize(kDeathFramesNum);
  for (std::size_t i{}; i < kDeathFramesNum; ++i) {
    auto tmp{fire_path};
    death_animation_[i].loadFromFile(tmp.append(std::to_string(i)).string() +
                                     ".png");
  }

  auto stay_path{path};
  stay_path.append("Stay").append("new");
  move_animation_.resize(kMoveFramesNum);
  for (std::size_t i{}; i < kMoveFramesNum; ++i) {
    auto tmp{stay_path};
    move_animation_[i].loadFromFile(tmp.append(std::to_string(i)).string() +
                                    ".png");
  }
}

Player::~Player() {}

void Player::Draw(Game &window, double round_time) {
  sf::Sprite move_sprite;
  if ((static_cast<std::ptrdiff_t>(std::round(round_time)) % 500) > 249) {
    move_sprite.setTexture(move_animation_[0]);
  } else {
    move_sprite.setTexture(move_animation_[1]);
  }

  move_sprite.scale(0.3, 0.3);
  auto window_size{window.GetWindow().getSize()};
  move_sprite.move(sf::Vector2f(0.f, 600.f));
  window.GetWindow().draw(move_sprite);
  word_drawer_.Draw(window.GetWindow());
}

void Player::InputSymbol(char symbol) { 
  word_drawer_.FillNextSymbol(symbol); 
}

std::string Player::GetWordResources(std::string file) {
  return fs::current_path()
      .append("WGAGameJam")
      .append("Game")
      .append("Game")
      .append("WordResources")
      .append(file)
      .string();
}
