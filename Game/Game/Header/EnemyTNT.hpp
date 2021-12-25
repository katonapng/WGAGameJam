#ifndef ENEMYTNT_HPP
#define ENEMYTNT_HPP


#include "../Header/Enemy.hpp"

class EnemyTNT : public Enemy {
public: 
  EnemyTNT();
  virtual ~EnemyTNT();

   void Draw(Game& window, double round_time);
  virtual void Damage();

protected:

  };


#endif  // ENEMYTNT_HPP