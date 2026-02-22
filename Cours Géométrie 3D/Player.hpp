#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Vector2D.h"

class Player {
protected : 

	int playerNumber;

	float speed;

	const float paddleWidth = 10.f;
	const float paddleHeight = 100.f;

	int score1;
	int score2;

	sf::Text text;
	sf::Text text2;
	sf::Font font;

public :

	sf::RectangleShape shapePlayer;

	Player(int playNumb, sf::RenderWindow& window);

	void playerMovement(float deltaTime, float wHeight);

	int getScore1();
	int getScore2();

	int setScoreUp1();
	int setScoreUp2();

	void update(float deltaTime, float wHeight);

	void drawPlayer(sf::RenderWindow& window);
};