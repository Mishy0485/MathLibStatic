#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.hpp"

int main()
{
    Maths::Matrix4<float> matrice4x4(1, 2, 0, 0, 0, 1, 3, 0, 0, 0, 1, 4, 0, 0, 0, 1);
    Maths::Vct3D<float> vector(3.2f, 5.6f, 8.7f);

    Game game("Pong de Quentinou et Maxinou", 1920, 1080);

    game.gameRun();
}