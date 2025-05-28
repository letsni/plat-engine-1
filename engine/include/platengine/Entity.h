#pragma once

namespace platengine {
    class Entity {
    public:
        virtual ~Entity() = default;
        virtual void update(float dt);
    };
}