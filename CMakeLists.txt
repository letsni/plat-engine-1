cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# 1. ���������� ������
add_library(platengine
    engine/src/RenderSystem.cpp
    engine/src/Entity.cpp
    engine/src/PhysicsSystem.cpp
    engine/src/InputSystem.cpp
    engine/src/ResourceManager.cpp
    engine/src/SceneManager.cpp
  "engine/include/platengine/components/Position.h" "engine/include/platengine/components/Velocity.h" "engine/include/platengine/components/Sprite.h" "engine/include/platengine/ComponentManager.h" "engine/include/platengine/Registry.h" "engine/include/platengine/MovementSystem.h" "engine/include/platengine/Game.h" "engine/src/Game.cpp")

target_include_directories(platengine PUBLIC
    ${CMAKE_SOURCE_DIR}/engine/include
)

# 2. ����������� ���� ����/�������
add_executable(main sample/littlePlatform/src/main.cpp "engine/include/platengine/components/Position.h" "engine/include/platengine/components/Velocity.h" "engine/include/platengine/components/Sprite.h" "engine/include/platengine/ComponentManager.h" "engine/include/platengine/Registry.h" "engine/include/platengine/MovementSystem.h" "engine/include/platengine/Game.h" "engine/src/Game.cpp")
target_link_libraries(platengine PUBLIC SFML::Graphics)
target_link_libraries(main PRIVATE platengine SFML::Graphics)

target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}/engine/include
)

set(SFML_ROOT "C:/Dev/SFML-3.0.0")