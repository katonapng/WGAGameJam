#include "../Headers/DrawGame.h"

DrawGame::DrawGame(sf::RenderWindow &window) {

	if (!background.loadFromFile("../GameImages/background.png")) {
		//handle error
	}

	float width = window.getSize().x;
	float height = window.getSize().y;

	sf::Vector2u backgroundSize = background.getSize();
	float scaleX = (float)width / backgroundSize.x;
	float scaleY = (float)height / backgroundSize.y;

	backgroundSprite.setPosition(0, 0);
	backgroundSprite.setTexture(background);
	backgroundSprite.setScale(scaleX, scaleY);
}

void DrawGame::Draw(sf::RenderWindow& window) {
	window.draw(backgroundSprite);
}