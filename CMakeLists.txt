cmake_minimum_required (VERSION 2.6)
project (Pong)
set (Pong_VERSION_MAJOR 0)
set (Pong_VERSION_MINOR 1)

include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_NAME "Pong")
add_executable (${EXECUTABLE_NAME} ball.cc paddle.cc game.cc pong.cc)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
find_package(Box2D REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${BOX2D_LIBRARY})

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
