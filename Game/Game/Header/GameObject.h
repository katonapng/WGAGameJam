#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class GameObject {

	size_t num_of_anim_picture = 0;

	//contains information about position of object
	sf::Vector2f object_position_;
	//damage
	float damage_ = 0;
	// contains number of animation
	unsigned char state_ = 0;

 
	std::vector<std::vector<std::string>> images_;
  sf::Texture  object_texture_;

	//sprite
	sf::Sprite object_sprite_;



	//TODO(igorkkkk) we can add variable for audiofile here
public:



	//changing the position of object
	sf::Vector2f GetPosition() const;
	void SetPosition(sf::Vector2f pos);
	//working with damage
	float GetDamage();
	void SetDamage(float dmg); 
	unsigned char GetState();
	void SetState(unsigned char st);
	void SetTexture(std::string);
	sf::Sprite& GetSprite();
	sf::Texture& GetTexture();
	void SetTexture(sf::Texture txt);
	std::vector<std::vector<std::string>>& GettSringM();
	void SetStringM(std::vector<std::vector<std::string>>& str_mass);

	//drawing
	//displays object one by one
	void DrawObject(sf::RenderWindow& window, unsigned char param = 0);
};