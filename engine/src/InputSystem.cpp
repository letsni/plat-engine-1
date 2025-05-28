#include "platengine/InputSystem.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

void InputSystem::processInput(sf::RenderWindow& window, float& playerX, float& playerY, bool& running) {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            running = false; // Управляем главным циклом
            window.close();
        }
    }
    // Клавиши для управления квадратом
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))  playerX -= 0.3f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) playerX += 0.3f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))    playerY -= 0.3f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))  playerY += 0.3f;
}