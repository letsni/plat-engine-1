#pragma once
#include "Registry.h"
#include "components/Position.h"
#include "components/Velocity.h"

class MovementSystem {
public:
    void update(Registry& registry, float dt) {
        for (Entity e : registry.getAliveEntities()) {
            auto pos = registry.getComponent<Position>(e);
            auto vel = registry.getComponent<Velocity>(e);
            if (pos && vel) {
                pos->x += vel->dx * dt;
                pos->y += vel->dy * dt;
            }
        }
    }
};