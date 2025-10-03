cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

# Configuración del estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Buscar SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Añadir el ejecutable
add_executable(snake_game src/main.cpp)

# Enlazar SFML
target_link_libraries(snake_game SFML::Graphics SFML::Window SFML::System)

# Habilitar testing con GoogleTest
enable_testing()
find_package(GTest REQUIRED)
add_executable(runTests tests/test_game.cpp)
target_link_libraries(runTests GTest::GTest GTest::Main)
