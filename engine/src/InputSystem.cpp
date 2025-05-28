#include "platengine/InputSystem.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

void InputSystem::processInput(sf::RenderWindow& window, float& playerX, float& playerY, bool& running) {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            running = false; // ��������� ������� ������
            window.close();
        }
    }
    // ������� ��� ���������� ���������
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))  playerX -= 3.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) playerX += 3.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))    playerY -= 3.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))  playerY += 3.f;
}