#pragma once
#include <SFML/Graphics.hpp>

class RenderSystem {
public:
    RenderSystem();

    void render(float playerX, float playerY);
    bool isWindowOpen() const;
    void closeWindow();

    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow window;
    sf::RectangleShape player;
};