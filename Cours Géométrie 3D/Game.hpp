#pragma once
#include "Player.hpp"
#include "Ball.hpp"
#include "Map.hpp"
#include "MathsLib.h"

class Game {
private : 

	std::string windowName;

	const unsigned int windowHeight;
	const unsigned int windowWidth;

public : 

	Game(std::string n, float width, float height);

	void gameRun();
	//void gameUpdate();
};