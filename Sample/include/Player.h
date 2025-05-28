#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"  // Подключаем базовый класс

class Player : public Entity {  // Наследуемся от Entity
public:
    Player() :
        shape(sf::Vector2f(50.f, 100.f)),
        velocity(0.f, 0.f),
        speed(300.f),
        jumpPower(850.f),
        isOnGround(false)
    {
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(sf::Vector2f(100.f, 600.f)); // начальная позиция
    }

    void handleInput() {
        velocity.x = 0.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            velocity.x -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            velocity.x += speed;
        // Прыжок
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && isOnGround) {
            velocity.y = -jumpPower;
            isOnGround = false;
        }
    }

    void update(float dt) override { // override обязательно!
        const float gravity = 1800.f;
        velocity.y += gravity * dt;
        shape.move(velocity * dt);

        // Простая симуляция "земли" на уровне y=700
        if (shape.getPosition().y + shape.getSize().y >= 700.f) {
            shape.setPosition(sf::Vector2f(shape.getPosition().x, 700.f - shape.getSize().y));
            velocity.y = 0.f;
            isOnGround = true;
        }
    }

    void draw(sf::RenderWindow& window) override { // override обязательно!
        window.draw(shape);
    }
private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    float speed;
    float jumpPower;
    bool isOnGround;
};