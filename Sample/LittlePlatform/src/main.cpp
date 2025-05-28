#include <SFML/Graphics/RenderWindow.hpp>
#include "platengine/RenderSystem.h"
#include "platengine/InputSystem.h"

int main() {
    sf::RenderWindow window{ sf::VideoMode({800, 600}), "Minimal Example" };

    RenderSystem renderSystem;
    InputSystem inputSystem;

    float playerX = 400, playerY = 300;
    bool running = true;

    while (window.isOpen() && running) {
        inputSystem.processInput(window, playerX, playerY, running);
        renderSystem.render(playerX, playerY);
    }
    return 0;
}











/*
#include <SFML/Graphics.hpp>
#include "../include/Player.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "CMake SFML Project");
    window.setFramerateLimit(144);

    Player player; // Добавили объект Player
    sf::Clock clock;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                //if we tap window closes
                window.close();
            }
        }

        player.handleInput();
        player.update(1.f / 144.f);

        window.clear();
        player.draw(window);
        window.display();
    }
}*/