#include "ball.h"

Ball::Ball()
: sf::RectangleShape(sf::Vector2f(10.0f, 10.0f))
{
	setPosition(sf::Vector2f(390.0f, 290.0f));
	m_speed = DEFAULT_BALL_SPEED_RIGHT;
}

Ball::Ball(const sf::Vector2f &position)
: sf::RectangleShape(sf::Vector2f(10.0f, 10.0f))
{
	setPosition(position);
	m_speed = DEFAULT_BALL_SPEED_RIGHT;
}

Ball::~Ball()
{
}

void Ball::reset()
{
	m_speed = DEFAULT_BALL_SPEED_RIGHT;
}

void Ball::reset(const sf::Vector2f &speed)
{
	setPosition(DEFAULT_BALL_POSITION);
	m_speed = speed;
}

void Ball::setSpeed(const sf::Vector2f &speed)
{
	m_speed = speed;
}

sf::Vector2f Ball::getSpeed()
{
	return m_speed;
}
