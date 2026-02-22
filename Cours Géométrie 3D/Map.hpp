#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Map {
protected :

	sf::RectangleShape ligneMid;

public : 

	Map();

	void createMap(sf::RenderWindow& window);
};