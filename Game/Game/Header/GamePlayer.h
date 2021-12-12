#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class GamePlayer {
	sf::Vector2f player_position_;
	float life_ = 100;
	unsigned char state_ = 0;
	sf::Texture  player_texture_;
	std::vector<std::vector<std::string>> images_ = {
		{"../Animation/Death/30.png","../Animation/Death/31.png","../Animation/Death/32.png","../Animation/Death/33.png","../Animation/Death/34.png","../Animation/Death/35.png"},
		{"../Animation/Stay/10.png","../Animation/Stay/11.png"},
		{"../Animation/Fire/20.png","../Animation/Fire/21.png","../Animation/Fire/22.png"}
	};
	size_t num_of_anim_picture = 0;
  sf::Sprite player_sprite_;
  
 public:
	 GamePlayer(uint32_t x = 0, uint32_t y = 0);
	GamePlayer(const GamePlayer& other);
	GamePlayer(GamePlayer&& tmp);

	// methods
	void ChangePosition(uint32_t x, uint32_t y);
	uint32_t GetX() const;
	uint32_t GetY() const;
	sf::Vector2f GetPosition() const;
	void SetX(uint32_t x);
	void SetY(uint32_t y);
	void SetPosition(sf::Vector2f pos);
	float GetLife();
	bool SetLife(float life_balance); //returns flag of all lifes (0-dead,1-alive)
	unsigned char GetState();
	void SetState(unsigned char st);
	void SetTexture(std::string);
	sf::Sprite& GetSprite();
  sf::Texture& GetTexture();
	void SetTexture(sf::Texture txt);
	std::vector<std::vector<std::string>>& GettSringM();
	void SetStringM(std::vector<std::vector<std::string>>& str_mass);
	


	//drawing  one by one
	void DrawPlayer(sf::RenderWindow& window, unsigned char param=0);

	// operators

	bool operator == (const GamePlayer& obj) const;
	bool operator != (GamePlayer& obj);
	GamePlayer& operator = (const GamePlayer& obj);

	GamePlayer& operator = (GamePlayer&& obj);

};

