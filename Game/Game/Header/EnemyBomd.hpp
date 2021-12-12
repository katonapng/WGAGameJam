#ifndef ENEMYBOMB_HPP
#define ENEMYBOMB_HPP


#include "../Header/Enemy.hpp"

class EnemyBomb : public Enemy {
public:
  EnemyBomb();
  virtual ~EnemyBomb();

   void Draw(Game& window, double round_time);
  virtual void Damage();

protected:

};


#endif  // ENEMYBOMB_HPP