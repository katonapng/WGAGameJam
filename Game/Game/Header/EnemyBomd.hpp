#ifndef ENEMYBOMB_HPP
#define ENEMYBOMB_HPP


#include "../Header/Enemy.hpp"

class EnemyBomb : public Enemy {
public:
  EnemyBomb(std::initializer_list<std::string> death = { {} }, std::initializer_list<std::string> move, double time = 5000);
  virtual ~EnemyBomb();

   void Draw(Game& window, double round_time);
  virtual void Damage();

protected:
  double final_time = 5000;
};


#endif  // ENEMYBOMB_HPP