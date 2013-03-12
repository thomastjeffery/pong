#include "paddle.h"

Paddle::Paddle()
: sf::RectangleShape(sf::Vector2f(10.0f, 100.0f))
{
	setPosition(sf::Vector2f(10.0f, 10.0f));
}

Paddle::Paddle(sf::Vector2f position)
: sf::RectangleShape(sf::Vector2f(10.0f, 100.0f))
{
	setPosition(position);
}

Paddle::~Paddle()
{
}

void Paddle::moveUp()
{
	// Stay in bounds
	if (getPosition().y > 0.0f)
		move(sf::Vector2f(0.0f, -10.0f));
}

void Paddle::moveDown()
{
	// Stay in bounds
	if (getPosition().y < 500.0f)
		move(sf::Vector2f(0.0f, 10.0f));
}
