#ifndef ENEMY_HPP
#define ENEMY_HPP


#include "../Header/GameObject.hpp"
#include "../Header/Game.hpp"

class Enemy : public GameObject {
public:
  Enemy(std::initializer_list<std::string> death, std::initializer_list<std::string> move,double time = 5000);
  virtual ~Enemy();

  void Draw( Game& window, double round_time);
  virtual void Damage();

protected:
  double final_time=5000;
};


#endif  // ENEMY_HPP

