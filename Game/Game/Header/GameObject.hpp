#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>

class Game;

class Game ;
class GameObject {
public:
  GameObject(std::initializer_list<std::string> death, std::initializer_list<std::string> move);
  inline GameObject() = default;
  inline virtual ~GameObject() {
    death_animation_.clear();
    move_animation_.clear();
  };

  virtual void Draw(Game &window, double round_time) = 0;

  inline const sf::Vector2f &GetPosition() { return position_; }

  virtual bool IsDead() { return health_points_ <= 0; }
  virtual void Damage();
  int Health() {
    return health_points_;
  }
protected:
  int health_points_=3;
  sf::Vector2f position_; // normalized position, that is, x and y ranges [0, 1]

  std::vector<sf::Texture> death_animation_;
  std::vector<sf::Texture> move_animation_;
};

#endif // GAMEOBJECT_HPP
