#pragma once

namespace platengine {
    class SceneManager {
    public:
        void init();
        void shutdown();
        void update(float dt);
    };
}