#include "GameObject.h"



//changing the position of object
sf::Vector2f GameObject::GetPosition() const {
	return object_position_;
};
void GameObject::SetPosition(sf::Vector2f pos) {
	object_position_ = pos;
};
//working with damage
float GameObject::GetDamage() {
	return damage_;
};
void GameObject::SetDamage(float dmg) {
	damage_ = dmg;
}; 
unsigned char GameObject::GetState() {
	return state_;
};
void GameObject::SetState(unsigned char st) {
	state_ = st;
};
void GameObject::SetTexture(std::string str) {
	object_texture_.loadFromFile(str);
};
sf::Sprite& GameObject::GetSprite() {
	return object_sprite_;
};
sf::Texture& GameObject::GetTexture() {
	return object_texture_;
};
void GameObject::SetTexture(sf::Texture txt) {
	object_texture_ = txt;
};
std::vector<std::vector<std::string>>& GameObject::GettSringM() {
	return images_;
};
void GameObject::SetStringM(std::vector<std::vector<std::string>>& str_mass) {
	images_ = str_mass;
};

void GameObject::DrawObject(sf::RenderWindow& window, unsigned char param) {

	if (++num_of_anim_picture > images_.at(param).size() - 1) {
		num_of_anim_picture = 0;
	}


	float width = window.getSize().x;
	float height = window.getSize().y;


	sf::Texture tmp;
	tmp.loadFromFile(images_.at(param).at(num_of_anim_picture));
	object_sprite_.setTexture(tmp);
	object_sprite_.setPosition(object_position_);


	//float scaleX = (float)width / tmp.getSize().x;
	//float scaleY = (float)height / tmp.getSize().y;
	//object_sprite_.setScale(scaleX, scaleY);

	window.draw(object_sprite_);
};