#include "GamePlayer.h"
#include <SFML/System/Clock.hpp>
//default constructor

GamePlayer::GamePlayer(uint32_t x, uint32_t y) {

	player_position_.x = x;
	player_position_.y = y;
};
//constructor
GamePlayer::GamePlayer(const GamePlayer& other) {
	player_position_ = other.player_position_;
};
//move constructor
GamePlayer::GamePlayer(GamePlayer&& tmp) {
	player_position_ = tmp.player_position_;
};

// methods
void GamePlayer::ChangePosition(uint32_t x, uint32_t y) {
	player_position_.x = x;
	player_position_.y = y;
};
uint32_t GamePlayer::GetX() const {
	return player_position_.x;
};
uint32_t GamePlayer::GetY() const {
	return player_position_.y;
};
sf::Vector2f GamePlayer::GetPosition() const {
	return player_position_;
};
void GamePlayer::SetX(uint32_t x) {
	player_position_.x = x;
};
void GamePlayer::SetY(uint32_t y) {
	player_position_.y = y;
};
void GamePlayer::SetPosition(sf::Vector2f pos) {
	player_position_ = pos;
};

float GamePlayer::GetLife() {
	return life_;
};

bool GamePlayer::SetLife(float life_balance) { //returns flag of all lifes (0-dead,1-alive)
	if (life_>0) {
    
		life_ += life_balance;
	}
	return life_>0;
};

unsigned char GamePlayer::GetState() {
	return state_;
};
void GamePlayer::SetState(unsigned char st) {
	state_ = st;
};
void GamePlayer::SetTexture(std::string str) {
	player_texture_.loadFromFile(str);
};
sf::Sprite& GamePlayer::GetSprite() {
	return player_sprite_;
};
sf::Texture& GamePlayer::GetTexture() {
	return player_texture_;
};
void GamePlayer::SetTexture(sf::Texture txt_mass) {
	player_texture_ = txt_mass;
};
std::vector<std::vector<std::string>>& GamePlayer::GettSringM() {
	return images_;
};
void GamePlayer::SetStringM(std::vector<std::vector<std::string>>& str_mass) {
	images_ = str_mass;
};
//drawing
void GamePlayer::DrawPlayer(sf::RenderWindow& window, unsigned char param) {

	if (++num_of_anim_picture > images_.at(param).size()-1) {
	num_of_anim_picture = 0;
  }


	float width = window.getSize().x;
	float height = window.getSize().y;

	sf::Texture tmp;
	tmp.loadFromFile(images_.at(param).at(num_of_anim_picture));
	player_sprite_.setTexture(tmp);
	player_sprite_.setPosition(player_position_);

	/*float scaleX = (float)width / tmp.getSize().x;
	float scaleY = (float)height / tmp.getSize().y;
	player_sprite_.setScale(scaleX, scaleY);*/

	window.draw(player_sprite_);
};
// operators

bool GamePlayer::operator == (const GamePlayer& obj) const {
	return (player_position_ == obj.player_position_);
};
bool GamePlayer::operator != (GamePlayer& obj) {
	return (player_position_ != obj.player_position_);
};
GamePlayer& GamePlayer::operator = (const GamePlayer& obj) {
	player_position_.y = obj.player_position_.y;
	player_position_.x = obj.player_position_.x;
	return *this;
};

GamePlayer& GamePlayer::operator = (GamePlayer&& obj) {
	player_position_.y = obj.player_position_.y;
	player_position_.x = obj.player_position_.x;
	return *this;
};


