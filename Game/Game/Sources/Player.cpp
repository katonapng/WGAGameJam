#include "../Headers/Player.hpp"
#include "../Headers/Game.hpp"

namespace fs = std::filesystem;

Player::Player()
    : GameObject{}, word_gen_{GetWordResources("words.txt")},
      word_drawer_{word_gen_.Generate(), GetWordResources("font.ttf"), 1080} {
  health_points_ = 3;

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
    death_animation_[i].setSmooth(true);
  }

  auto fire_path{path};
  fire_path.append("Fire").append("new");
  fire_animation_.resize(kFireFramesNum);
  for (std::size_t i{}; i < kFireFramesNum; ++i) {
    auto tmp{fire_path};
    fire_animation_[i].loadFromFile(tmp.append(std::to_string(i)).string() +
                                    ".png");
    fire_animation_[i].setSmooth(true);
  }

  auto stay_path{path};
  stay_path.append("Stay").append("new");
  move_animation_.resize(kMoveFramesNum);
  for (std::size_t i{}; i < kMoveFramesNum; ++i) {
    auto tmp{stay_path};
    move_animation_[i].loadFromFile(tmp.append(std::to_string(i)).string() +
                                    ".png");
    move_animation_[i].setSmooth(true);
  }

  auto health_path{path};
  health_path.append("Health");
  health_textures_.resize(kHealthFramesNum);
  for (std::size_t i{}; i < kHealthFramesNum; ++i) {
    auto tmp{health_path};
    health_textures_[i].loadFromFile(tmp.append(std::to_string(i)).string() +
                                     ".png");
    health_textures_[i].setSmooth(true);
  }
}

Player::~Player() {}

void Player::Draw(Game &window, double round_time) {
  static double animation_start_time{};

  sf::Sprite player_sprite;
  if (health_points_ > 0) {
    if (word_drawer_.GetCursor() < word_drawer_.GetWordSize()) {
      player_sprite.setTexture(
          move_animation_[(static_cast<std::ptrdiff_t>(std::round(round_time)) %
                           (kMoveFramesNum * 250)) /
                          250]);

      animation_start_time = round_time;
    } else {
      auto animation_index{(static_cast<std::ptrdiff_t>(
                                std::round(round_time - animation_start_time)) %
                            ((kFireFramesNum + 1) * 100)) /
                           100};

      if (animation_index == kFireFramesNum) {
        word_drawer_.SetNewWord(word_gen_.Generate());
        player_sprite.setTexture(fire_animation_[animation_index - 1]);
      } else {
        player_sprite.setTexture(fire_animation_[animation_index]);
      }
    }
  } else {
    auto animation_index{(static_cast<std::ptrdiff_t>(
                              std::round(round_time - animation_start_time)) %
                          ((kDeathFramesNum + 1) * 100)) /
                         100};

    if (animation_index == kDeathFramesNum) {
      health_points_ = 3;
      word_drawer_.SetNewWord(word_gen_.Generate());
      player_sprite.setTexture(death_animation_[animation_index - 1]);
    } else {
      player_sprite.setTexture(death_animation_[animation_index]);
    }
  }

  player_sprite.scale(0.3, 0.3);
  auto window_size{window.GetWindow().getSize()};
  player_sprite.move(sf::Vector2f(0.f, 600.f));
  window.GetWindow().draw(player_sprite);

  sf::Sprite health_sprite;
  health_sprite.setTexture(health_textures_[health_points_]);
  health_sprite.scale(0.05, 0.05);
  health_sprite.move(sf::Vector2f(10.f, 10.f));
  window.GetWindow().draw(health_sprite);

  word_drawer_.Draw(window.GetWindow());
}

void Player::Damage() { --health_points_; }

void Player::InputSymbol(char symbol) {
  if (!word_drawer_.FillNextSymbol(symbol)) {
    --health_points_;
  }
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
