#pragma once
#include <SFML/Graphics.hpp>

namespace platengine {

    class Entity {
    public:
        virtual ~Entity() = default;
        virtual void update(float dt) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
    };

}