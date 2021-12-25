#ifndef ENEMY_HPP
#define ENEMY_HPP


#include "GameObject.hpp"
class Game;
class Enemy : public GameObject {
public:
  Enemy(std::initializer_list<std::string> death, 
    std::initializer_list<std::string> move,double time = 15000);
  virtual ~Enemy();

  void Draw( Game& window, double round_time);

  virtual void Damage();
  double IsDeadTime(double round_time) {
    return (final_time-round_time);
  }
  void ChangeTime(double time);
  double GetTime() { return final_time; };
protected:
  double final_time=5000;
};


#endif  // ENEMY_HPP

