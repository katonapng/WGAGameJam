#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


class DrawGame {


public:
	DrawGame(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture background;
	sf::Sprite backgroundSprite;
};