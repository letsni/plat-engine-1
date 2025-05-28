#pragma once

namespace platengine {
    class PhysicsSystem {
    public:
        void init();
        void shutdown();
        void update(float dt);
    };
}