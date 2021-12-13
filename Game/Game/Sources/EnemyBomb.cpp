#include"../Headers/EnemyBomd.hpp"
EnemyBomb::EnemyBomb():Enemy(
  { "Animation/Bomb/Explosion/new/ispraaavboma00.png","Animation/Bomb/Explosion/new/ispraaavboma01.png","Animation/Bomb/Explosion/new/ispraaavboma02.png",
  "Animation/Bomb/Explosion/new/ispraaavboma03.png","Animation/Bomb/Explosion/new/ispraaavboma04.png",
  "Animation/Bomb/Explosion/new/ispraaavboma05.png","Animation/Bomb/Explosion/new/ispraaavboma06.png",
  "Animation/Bomb/Explosion/new/ispraaavboma07.png","Animation/Bomb/Explosion/new/ispraaavboma08.png",
  "Animation/Bomb/Explosion/new/ispraaavboma09.png" }, {
    "Animation/Bomb/Walking/new/bombaispravl00.png","Animation/Bomb/Walking/new/bombaispravl01.png","Animation/Bomb/Walking/new/bombaispravl02.png",
  "Animation/Bomb/Walking/new/bombaispravl03.png","Animation/Bomb/Walking/new/bombaispravl04.png",
  "Animation/Bomb/Walking/new/bombaispravl05.png","Animation/Bomb/Walking/new/bombaispravl06.png",
  "Animation/Bomb/Walking/new/bombaispravl07.png","Animation/Bomb/Walking/new/bombaispravl08.png",
  "Animation/Bomb/Walking/new/bombaispravl09.png" },5000) {
	
};
EnemyBomb::~EnemyBomb() {};

void EnemyBomb::Draw(Game& window, double round_time) {
	Enemy::Draw(window, round_time);
};
void EnemyBomb::Damage() {health_points_ -= 3; };