#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "WordDrawer.hpp"
#include "WordGenerator.hpp"
#include <cmath>
#include <filesystem>

class Player : public GameObject {
public:
  Player();

  virtual ~Player();

  virtual void Draw(Game &window, double round_time);

  void Damage();

  void InputSymbol(char symbol);

protected:
  static std::string GetWordResources(std::string file);

  std::vector<sf::Texture> fire_animation_;
  std::vector<sf::Texture> health_textures_;
  WordsGenerator word_gen_;
  WordDrawer word_drawer_;

  
  static constexpr std::size_t kFireFramesNum{10};
  static constexpr std::size_t kDeathFramesNum{5};
  static constexpr std::size_t kMoveFramesNum{2};
  static constexpr std::size_t kHealthFramesNum{4};
  bool flagEnd_ = 0;
public:
  bool End() {
    return flagEnd_;
  }
  bool GetState() { 
    bool tmp = word_drawer_.GetInputRes();
    if (!word_drawer_.GetInputRes()) {
    word_drawer_.SetNewWord(word_gen_.Generate());
    } 
    return tmp;
  }
};

#endif // PLAYER_HPP
