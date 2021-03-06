
#include "../Header/GameObject.hpp"
#include "../Header/Game.hpp"


GameObject::GameObject(std::initializer_list<std::string> death, std::initializer_list<std::string> move) {

	auto itb_death = death.begin();
	auto itb_move = move.begin();
	auto ite_death = death.end();
	auto ite_move = move.end();
	for (; itb_death != ite_death; itb_death++) {
		sf::Texture tmp;
		tmp.loadFromFile(*itb_death);
		tmp.setSmooth(true);
		death_animation_.push_back(tmp);
	}
	for (; itb_move != ite_move; itb_move++) {
		sf::Texture tmp;
		tmp.loadFromFile(*itb_move);
		tmp.setSmooth(true);
		move_animation_.push_back(tmp);
	}

	position_.x = 0.8;
	position_.y = 0.6;

};



void GameObject::Draw(Game& window, double round_time) {


};
void GameObject::Damage() { health_points_ -= 3; };


