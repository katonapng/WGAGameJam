#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

class Player : public GameObject {
 public:
	Player();
  virtual ~Player();

  virtual void Draw(Game& window, double round_time);
  virtual void Damage();

protected:
	std::vector<sf::Texture> fire_animation_;
  std::vector<sf::Texture> health_;
};


#endif  // PLAYER_HPP
