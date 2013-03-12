#include "game.h"

Game::Game(sf::VideoMode mode, char const* title)
: sf::RenderWindow(mode, title)
{
	objects.push_front(sf::RectangleShape(sf::Vector2f(100.0f, 100.0f)));
}

Game::~Game()
{
}

// Handles events for a window
void Game::handle_events()
{
	sf::Event event;
	while (this->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				this->close();
				break;
			case sf::Event::Resized:
				// Resize the view to the size of the window, so we don't skew everything.
				this->setView(sf::View(sf::FloatRect(0.0f, 0.0f,
							static_cast<float>(this->getSize().x),
							static_cast<float>(this->getSize().y))));
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Space:
					objects.push_front(sf::RectangleShape(sf::Vector2f(10.0f, 10.0f)));
					break;
				}
				break;
			default:
				break;
		}
	}
}

// Physics step
void Game::step()
{
	// Move objects
	for (std::list<sf::RectangleShape>::iterator it = objects.begin(); it != objects.end(); ++it)
	{
	}
}

// Draws on a RenderWindow
void Game::draw_objects()
{
	// Clear the window
	this->clear();

	// Draw the objects
	for (std::list<sf::RectangleShape>::iterator it = objects.begin(); it != objects.end(); ++it)
		this->draw(*it);

	// Flip the buffer so we can see what's been drawn on it.
	this->display();
}

void Game::calc_time()
{
	elapsedTime = clock.getElapsedTime().asSeconds();
	clock.restart();
}
