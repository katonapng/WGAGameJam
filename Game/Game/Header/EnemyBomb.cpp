#include"../Header/EnemyBomd.hpp"
EnemyBomb::EnemyBomb(std::initializer_list<std::string> death, std::initializer_list<std::string> move, double time = 5000) {
	
};
EnemyBomb::~EnemyBomb() {};

void EnemyBombDraw(Game& window, double round_time);
virtual void Damage();