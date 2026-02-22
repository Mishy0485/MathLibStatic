#include "Map.hpp"

Map::Map()
{

}

void Map::createMap(sf::RenderWindow& window)
{
	ligneMid.setSize(sf::Vector2f(25.f, 1080.f));
	ligneMid.setPosition(sf::Vector2f(1920 / 2, 0));
	ligneMid.setFillColor(sf::Color(255, 255, 255, 20));
	window.draw(ligneMid);
}