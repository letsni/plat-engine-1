#include <SFML/Graphics.hpp>
#include "Player.h"

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
                window.close();
            }
        }

        player.handleInput();
        player.update(1.f / 144.f);

        window.clear();
        player.draw(window);
        window.display();
    }
}