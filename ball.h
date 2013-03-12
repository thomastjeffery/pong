#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Ball : public sf::RectangleShape
{
public:
	Ball();
	Ball(sf::Vector2f position);
	virtual ~Ball();

	void setSpeed(const sf::Vector2f &speed);
	sf::Vector2f getSpeed();

private:
	sf::Vector2f m_speed;
};

#endif
