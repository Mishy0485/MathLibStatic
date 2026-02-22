#include "Game.hpp"

Game::Game(std::string n, float width, float height) : windowName(n), windowHeight(height), windowWidth(width) {}

void Game::gameRun()
{
    sf::RenderWindow window(sf::VideoMode({ windowWidth, windowHeight }), windowName, sf::State::Fullscreen);
    window.setFramerateLimit(60);

    sf::Clock clock;
    clock.start();


    Map map;
    Player joueur1(1, window);
    Player joueur2(2, window);
    Ball ball(windowWidth / 2, windowHeight / 2);

    while (window.isOpen())
    {
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }
        joueur1.update(deltaTime, windowHeight);
        joueur2.update(deltaTime, windowHeight);
        ball.update(deltaTime, joueur1, joueur2, windowHeight, windowWidth);

        window.clear();
        map.createMap(window);
        joueur1.drawPlayer(window);
        joueur2.drawPlayer(window);
        ball.drawBall(window);

        window.display();
    }
}
