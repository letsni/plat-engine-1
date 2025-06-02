#include "platengine/RenderSystem.h"

RenderSystem::RenderSystem()
    : window(sf::VideoMode({ 800, 600 }), "Minimal Example")
{
    player.setSize({ 50, 50 });
    player.setFillColor(sf::Color::Blue);
    player.setOrigin({ 25, 25 }); // Center origin
}

void RenderSystem::render(float playerX, float playerY) {
    window.clear(sf::Color::Black);
    player.setPosition({ playerX, playerY });
    window.draw(player);
    window.display();
}

bool RenderSystem::isWindowOpen() const {
    return window.isOpen();
}

void RenderSystem::closeWindow() {
    window.close();
}
sf::RenderWindow& RenderSystem::getWindow() {
    return window;
}