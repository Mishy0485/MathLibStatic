#pragma once
#include "Player.hpp"
#include "Vector2D.h"

class Ball {
protected : 

	float x, y;

	sf::CircleShape ball;
	Maths::Vct2D<float> ballVelocity;
	Maths::Vct2D<float> position;

	const float ballRadius = 20.f;

	const float speed = 600.f;

	float angle = 0;

public : 

	Ball(float xPos, float yPos);
	~Ball();

	void ballMovement(float deltaTime);

	void ballCollision(Player& player1, Player& player2, float windowHeight);

	bool intersectsBall(const sf::FloatRect& a, const sf::FloatRect& b);

	void ballReset(float height, float width, Player& player1, Player& player2);

	void update(float deltaTime, Player& player1, Player& player2, float wHeight, float wWidth);

	void drawBall(sf::RenderWindow& window);
};