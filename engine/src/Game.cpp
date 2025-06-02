#include "platengine/Game.h"
#include "platengine/components/Position.h"
#include "platengine/components/Velocity.h"
#include "platengine/components/Sprite.h"
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

Game::Game() {
    // �������� ������ � ���������� �����������
    player = 1;
    componentManager.addComponent<Position>(player, Position{ 400, 300 });
    componentManager.addComponent<Velocity>(player, Velocity{ 0, 0 });
    //componentManager.addComponent<Sprite>(player, Sprite{/* ������������� �������, ���� ����� */});
}

void Game::run() {
    bool running = true;
    sf::Clock clock;
    while (renderSystem.isWindowOpen() && running) {
        float dt = clock.restart().asSeconds();

        handleInput(dt, running);
        update(dt);
        render();
    }
}

void Game::handleInput(float /*dt*/, bool& running) {
    sf::RenderWindow& window = renderSystem.getWindow();
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            running = false;
            window.close();
        }
        auto* vel = componentManager.getComponent<Velocity>(player);
        if (vel) {
            vel->dx = 0;
            vel->dy = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))  vel->dx = -200;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) vel->dx = 200;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))    vel->dy = -200;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))  vel->dy = 200;
        }


        // ������ ��������� ������ ����� ������� ��� �������������
    }
}

void Game::update(float dt) {
    // ������ ���������� ������� ������
    auto* pos = componentManager.getComponent<Position>(player);
    auto* vel = componentManager.getComponent<Velocity>(player);
    if (pos && vel) {
        pos->x += vel->dx * dt;
        pos->y += vel->dy * dt;
    }

    // ��� ����� ��������� ������ �������, �������� ������
    // physicsSystem.update(...);
}

void Game::render() {
    // ������� ������� � ������� � ������-�������
    auto* pos = componentManager.getComponent<Position>(player);
    if (pos) {
        renderSystem.render(pos->x, pos->y);
    }
}