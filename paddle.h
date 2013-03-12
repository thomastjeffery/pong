#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Paddle : public sf::RectangleShape
{
public:
	Paddle();
	Paddle(sf::Vector2f position);
	virtual ~Paddle();

	void moveUp();
	void moveDown();

private:
};

#endif
