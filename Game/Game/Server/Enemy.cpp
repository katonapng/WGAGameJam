#include"../Header/Enemy.hpp"
#include "../Header/Game.hpp"
Enemy::Enemy(std::initializer_list<std::string> death,
	std::initializer_list<std::string> move,double time):GameObject(death,move)
	{
	for (auto a : death) {
		for (auto b : a) {

		}
	}
	final_time = time;
	health_points_ = 4;
	position_.x = 0.8;
};
Enemy::~Enemy() {};

 void Enemy::Draw(Game& window, double round_time) {


	 if ((round_time <= final_time)) {
		
			 position_.x = float(((final_time - round_time)/final_time)*(1-0.26))+0.26;
		size_t sz =  GameObject::move_animation_.size();
		sf::Sprite tmp_spr;
		int time = (int(final_time - round_time)/250) % (sz);
		
		tmp_spr.setTexture(GameObject::move_animation_.at(sz-time-1));
		tmp_spr.setScale(416.f /tmp_spr.getTexture()->getSize().y, 416.f / tmp_spr.getTexture()->getSize().y);
		tmp_spr.setPosition(sf::Vector2f(window.GetWindow().getSize().x * position_.x, 
		
			window.GetWindow().getSize().y * position_.y));
		
		 window.GetWindow().draw(tmp_spr);
	 }
	 else {
	
		 position_.x = 0.26;
			size_t sz = GameObject::death_animation_.size();
			sf::Sprite tmp_spr;
			int time = (std::abs(int(final_time - round_time)/200) % (sz));
			tmp_spr.setTexture(GameObject::death_animation_.at(time));
			if ((sz - 2) == time) {
				health_points_ = 0;
			}
			else if((sz - 1) == time)
			{
				health_points_ = 3;
			}
			tmp_spr.setScale(416.f / tmp_spr.getTexture()->getSize().y, 416.f / tmp_spr.getTexture()->getSize().y);
			tmp_spr.setPosition(sf::Vector2f(window.GetWindow().getSize().x*position_.x,
				window.GetWindow().getSize().y * position_.y));
		//	std::cout<< window.GetWindow().getSize().x << std::endl;
			window.GetWindow().draw(tmp_spr);
		 
	 }

 };
 void Enemy::Damage() { GameObject::health_points_ -= 3; };

 void Enemy::ChangeTime(double time) {
	 final_time = time;
 };