#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Game ;
class GameObject {
public:
  GameObject(std::initializer_list<std::string> death, std::initializer_list<std::string> move);

  virtual ~GameObject();


  virtual void Draw( Game& window, double round_time) = 0;


  inline const sf::Vector2f& GetPosition() { return position_; }

  virtual void Damage() = 0;

  inline bool IsDead() { return health_points_ <= 0; }

protected:
  int health_points_;
  sf::Vector2f position_; // normalized position, that is, x and y ranges [0, 1]

  std::vector<sf::Texture> death_animation_;
  std::vector<sf::Texture> move_animation_;

};

#endif // GAMEOBJECT_HPP
