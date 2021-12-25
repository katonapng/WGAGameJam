#include"../Header/EnemyTNT.hpp"
EnemyTNT::EnemyTNT() :Enemy(
  { "Animation/TNT/Explosion/new/dinavzrisprrr0.png","Animation/TNT/Explosion/new/dinavzrisprrr1.png","Animation/TNT/Explosion/new/dinavzrisprrr2.png",
  "Animation/TNT/Explosion/new/dinavzrisprrr3.png","Animation/TNT/Explosion/new/dinavzrisprrr4.png",
  "Animation/TNT/Explosion/new/dinavzrisprrr5.png","Animation/TNT/Explosion/new/dinavzrisprrr6.png",
  "Animation/TNT/Explosion/new/dinavzrisprrr7.png","Animation/TNT/Explosion/new/dinavzrisprrr8.png" },
  {
    "Animation/TNT/Walking/new/dinaaaispr0.png","Animation/TNT/Walking/new/dinaaaispr1.png","Animation/TNT/Walking/new/dinaaaispr2.png",
  "Animation/TNT/Walking/new/dinaaaispr3.png","Animation/TNT/Walking/new/dinaaaispr4.png",
  "Animation/TNT/Walking/new/dinaaaispr5.png","Animation/TNT/Walking/new/dinaaaispr6.png",
  "Animation/TNT/Walking/new/dinaaaispr7.png","Animation/TNT/Walking/new/dinaaaispr8.png" }, 15000) {

};
EnemyTNT::~EnemyTNT() {};

void EnemyTNT::Draw(Game& window, double round_time) {
	Enemy::Draw(window, round_time);
};
void EnemyTNT::Damage() { health_points_ -= 3; };