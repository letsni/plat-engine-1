#pragma once
#include "platengine/InputSystem.h"
#include "platengine/PhysicsSystem.h"
#include "platengine/RenderSystem.h"
#include "platengine/ComponentManager.h"
#include "platengine/Entity.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class Game {
public:
    Game();
    void run();
private:
    InputSystem inputSystem;
    platengine::PhysicsSystem physicsSystem;
    RenderSystem renderSystem;
    ComponentManager componentManager;

    Entity player;

    void handleInput(float dt, bool& running);
    void update(float dt);
    void render();
};