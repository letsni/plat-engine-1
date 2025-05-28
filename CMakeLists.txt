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

# 1. Библиотека движка
add_library(platengine
    engine/src/RenderSystem.cpp
    engine/src/Entity.cpp
    engine/src/PhysicsSystem.cpp
    engine/src/InputSystem.cpp
    engine/src/ResourceManager.cpp
    engine/src/SceneManager.cpp
 "engine/src/aaa.cpp")

target_include_directories(platengine PUBLIC
    ${CMAKE_SOURCE_DIR}/engine/include
)

# 2. Исполняемый файл игры/примера
add_executable(main sample/littlePlatform/src/main.cpp)
target_link_libraries(platengine PUBLIC SFML::Graphics)
target_link_libraries(main PRIVATE platengine SFML::Graphics)

target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}/engine/include
)

set(SFML_ROOT "C:/Dev/SFML-3.0.0")