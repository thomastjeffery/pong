#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
//#include <list>
#include "paddle.h"
#include "ball.h"

class Game : public sf::RenderWindow
{
public:
	Game(sf::VideoMode mode, char const* title);
	virtual ~Game();

	void handle_events();
	void handle_collisions();
	void step();
	void draw_objects();
	void calc_time();

private:
	//std::list<sf::RectangleShape> objects;
	Paddle *m_player1;
	Paddle *m_player2;
	Ball *m_ball;
	sf::Clock m_clock;
	float m_elapsedTime;
};

#endif
