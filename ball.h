#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

const sf::Vector2f DEFAULT_BALL_POSITION = sf::Vector2f(390.0f, 290.0f);
const sf::Vector2f DEFAULT_BALL_SPEED_RIGHT = sf::Vector2f(200.0f, 100.0f);
const sf::Vector2f DEFAULT_BALL_SPEED_LEFT = sf::Vector2f(-200.0f, 100.0f);

class Ball : public sf::RectangleShape
{
public:
	Ball();
	Ball(const sf::Vector2f &position);
	virtual ~Ball();

	void reset();
	void reset(const sf::Vector2f &speed);

	void setSpeed(const sf::Vector2f &speed);
	sf::Vector2f getSpeed();

private:
	sf::Vector2f m_speed;
};

#endif
