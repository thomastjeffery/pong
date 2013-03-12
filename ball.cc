#include "ball.h"

Ball::Ball()
: sf::RectangleShape(sf::Vector2f(10.0f, 10.0f))
{
	setPosition(sf::Vector2f(390.0f, 290.0f));
	m_speed = sf::Vector2f(200.0f, 100.0f);
}

Ball::Ball(sf::Vector2f position)
: sf::RectangleShape(sf::Vector2f(10.0f, 10.0f))
{
	setPosition(position);
	m_speed = sf::Vector2f(200.0f, 100.0f);
}

Ball::~Ball()
{
}

void Ball::setSpeed(const sf::Vector2f &speed)
{
	m_speed = speed;
}

sf::Vector2f Ball::getSpeed()
{
	return m_speed;
}
