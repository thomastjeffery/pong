#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <list>
#include "PongConfig.h"

class Game : public sf::RenderWindow
{
public:
	Game(sf::VideoMode mode, char const* title);
	virtual ~Game();

	void handle_events();
	void step();
	void draw_objects();
	void calc_time();

private:
	std::list<sf::RectangleShape> objects;
	sf::Clock clock;
	float elapsedTime;
};

#endif
