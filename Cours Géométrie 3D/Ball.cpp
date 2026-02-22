#include "Ball.hpp"
#include "SFML/Graphics.hpp"


Ball::Ball(float xPos, float yPos) : x(xPos), y(yPos)
{
	position.SetVector2D(x, y);
	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(position);

	ballVelocity.SetVector2D(speed, speed);

}

Ball::~Ball()
{
}

void Ball::ballMovement(float deltaTime) {
	ball.move(ballVelocity * deltaTime);
}

bool Ball::intersectsBall(const sf::FloatRect& a, const sf::FloatRect& b)
{
	return (a.position.x < b.position.x + b.size.x) &&
		   (a.position.x + a.size.x > b.position.x) &&
		   (a.position.y < b.position.y + b.size.y) &&
		   (a.position.y + a.size.y > b.position.y);
}

void Ball::ballCollision(Player& player1, Player& player2, float windowHeight)
{
	if (ball.getPosition().y <= 0 || ball.getPosition().y + ballRadius * 2 >= windowHeight) {
		ballVelocity.SetY(-ballVelocity.GetY());
	}

	if (intersectsBall(ball.getGlobalBounds(), player1.shapePlayer.getGlobalBounds())) {
		ballVelocity.SetX(-ballVelocity.GetX());
	}
	else if (intersectsBall(ball.getGlobalBounds(), player2.shapePlayer.getGlobalBounds())) {
		ballVelocity.SetX(-ballVelocity.GetX());
	}
}

void Ball::ballReset(float height, float width, Player& player1, Player& player2)
{
	if (ball.getPosition().x < 0) {
		ball.setPosition(sf::Vector2f((width - ballRadius) / 2, (height - ballRadius) / 2));
		player2.setScoreUp2();
		ballVelocity.SetX(-ballVelocity.GetX());  // Changer de direction
	}
	else if (ball.getPosition().x > width) {
		ball.setPosition(sf::Vector2f((width - ballRadius) / 2, (height - ballRadius) / 2));
		player1.setScoreUp1();
		ballVelocity.SetX(-ballVelocity.GetX());  // Changer de direction
	}
}

void Ball::update(float deltaTime, Player& player1, Player& player2, float wHeight, float wWidth) {
	ballMovement(deltaTime);
	ballCollision(player1, player2, wHeight);
	ballReset(wHeight, wWidth, player1, player2);
}

void Ball::drawBall(sf::RenderWindow& window)
{
	window.draw(ball);
}