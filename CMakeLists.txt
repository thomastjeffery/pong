cmake_minimum_required (VERSION 2.6)
project (Pong)
set (Pong_VERSION_MAJOR 0)
set (Pong_VERSION_MINOR 1)

configure_file (
	"${PROJECT_SOURCE_DIR}/PongConfig.h.in"
	"${PROJECT_BINARY_DIR}/PongConfig.h"
	)

include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_NAME "Pong")
add_executable (${EXECUTABLE_NAME} game.cc pong.cc)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
