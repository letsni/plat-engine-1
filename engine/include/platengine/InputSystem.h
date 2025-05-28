#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputSystem {
public:
    void processInput(sf::RenderWindow& window, float& playerX, float& playerY, bool& running);
};