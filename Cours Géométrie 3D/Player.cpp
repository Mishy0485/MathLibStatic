#include "Player.hpp"

Player::Player(int playNumb, sf::RenderWindow& window) : playerNumber(playNumb), text(font), text2(font)
{
	shapePlayer.setSize(Maths::Vct2D<float>(paddleWidth, paddleHeight));
	shapePlayer.setOutlineThickness(10.f);

	if (playNumb == 1) {
		shapePlayer.setFillColor(sf::Color::Green);
		shapePlayer.setOutlineColor(sf::Color::Blue);
		shapePlayer.setPosition(Maths::Vct2D<float>(240, window.getSize().y / 2));
	}
	else if (playNumb == 2) {
		shapePlayer.setFillColor(sf::Color::Red);
		shapePlayer.setOutlineColor(sf::Color::Magenta);
		shapePlayer.setPosition(Maths::Vct2D<float>(1680, window.getSize().y / 2));
	}
	else {
		std::cout << "error creation player select playNumb : 1 or 2" << std::endl << std::endl;
	}

	if (!font.openFromFile("assets\\Minecraft.ttf")) {
		std::cerr << "Erreur lors du chargement de la police" << std::endl;
	}

	text.setFont(font); // a font is required to make a text object
	// set the string to display
	//text.setString("Score: " + std::to_string(score1));
	// set the character size
	text.setCharacterSize(80); // in pixels, not points!
	// set the color
	text.setFillColor(sf::Color::White);
	// set the text style
	text.setStyle(sf::Text::Bold);
	text.setPosition(Maths::Vct2D<float>(240, 80));

	text2.setFont(font); // a font is required to make a text object
	// set the string to display
	//text2.setString("Score: " + std::to_string(score2));
	// set the character size
	text2.setCharacterSize(80); // in pixels, not points!
	// set the color
	text2.setFillColor(sf::Color::White);
	// set the text style
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(Maths::Vct2D<float>(1300, 80));
}

void Player::playerMovement(float deltaTime, float wHeight)
{
	if (playerNumber == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			speed = 1200.f * deltaTime;
		}
		else {
			speed = 800.f * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
			shapePlayer.move(Maths::Vct2D<float>(0, -speed));
			if (shapePlayer.getPosition().y <= 10) {
				shapePlayer.setPosition(Maths::Vct2D<float>(shapePlayer.getPosition().x, 10));
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			shapePlayer.move(Maths::Vct2D<float>(0, speed));
			if (shapePlayer.getPosition().y >= wHeight - 110) {
				shapePlayer.setPosition(Maths::Vct2D<float>(shapePlayer.getPosition().x, wHeight - 110));
			}
		}
	}
	else if (playerNumber == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)) {
			speed = 1200.f * deltaTime;
		}
		else {
			speed = 800.f * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			shapePlayer.move(Maths::Vct2D<float>(0, -speed));
			if (shapePlayer.getPosition().y <= 10) {
				shapePlayer.setPosition(Maths::Vct2D<float>(shapePlayer.getPosition().x, 10));
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			shapePlayer.move(Maths::Vct2D<float>(0, speed));
			if (shapePlayer.getPosition().y >= wHeight - 110) {
				shapePlayer.setPosition(Maths::Vct2D<float>(shapePlayer.getPosition().x, wHeight - 110));
			}
		}
	}
}

int Player::getScore1()
{
	return score1;
}

int Player::getScore2()
{
	return score2;
}

int Player::setScoreUp1()
{
	score1++;
	return score1;
}

int Player::setScoreUp2()
{
	score2++;
	return score2;
}

void Player::update(float deltaTime, float wHeight) {
	playerMovement(deltaTime, wHeight);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(shapePlayer);

	if (playerNumber == 1) {
		text.setString("Score: " + std::to_string(score1));
		window.draw(text);
	}
	else if (playerNumber == 2) {
		text2.setString("Score: " + std::to_string(score2));
		window.draw(text2);
	}
}