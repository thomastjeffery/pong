#include "game.h"

Game::Game(sf::VideoMode mode, char const* title)
: sf::RenderWindow(mode, title)
{
	m_player1 = new Paddle(sf::Vector2f(10.0f, 10.0f));
	m_player2 = new Paddle(sf::Vector2f(780.0f, 10.0f));
	m_ball = new Ball(sf::Vector2f(395.0f, 295.0f));
}

Game::~Game()
{
	delete m_player1;
	delete m_player2;
	delete m_ball;
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
				break;
			default:
				break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_player1->moveUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_player1->moveDown();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_player2->moveUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_player2->moveDown();
}

// Handle ball collisions and scoring
void Game::handle_collisions()
{
	sf::Vector2f ball_position = m_ball->getPosition();
	sf::Vector2f ball_speed = m_ball->getSpeed();
	sf::Vector2f player1_position = m_player1->getPosition();
	sf::Vector2f player2_position = m_player2->getPosition();

	//Move the ball
	// Bounce if we hit the floor or ceiling
	if (ball_position.y >= 590.0f) // We hit the floor
	{
		if (ball_speed.y >= 0) // Positive means we're moving down
			// start moving up
			m_ball->setSpeed(sf::Vector2f(ball_speed.x, m_ball->getSpeed().y * -1));
	}
	else if (ball_position.y <= 0.0f) // We hit the cieling
	{
		if (ball_speed.y <= 0) // Negative means we're moving up
			// start moving down
			m_ball->setSpeed(sf::Vector2f(ball_speed.x, m_ball->getSpeed().y * -1));
	}

	// Bounce if it hits a paddle
	if (ball_position.x <= 20.0f) // We might be hit by player 1's paddle
	{
		if (ball_position.y >= (player1_position.y - 10.0f)
				&&
			ball_position.y <= (player1_position.y + 100.0f))
		{
			if (ball_speed.x <= 0) // Ball is moving left
			{
				// Move right and add distance from center of paddle to ball vector
				float distance = player1_position.y + 50.0f - ball_position.y + 5.0f;

				if (ball_position.y + 5.0f < player1_position.y + 50.0f)
					m_ball->setSpeed(sf::Vector2f(ball_speed.x * -1,
								-ball_speed.y - 10*distance));
				else if (ball_position.y + 5.0f >= player1_position.y + 50.0f)
					m_ball->setSpeed(sf::Vector2f(ball_speed.x * -1,
								ball_speed.y - 10*distance));
			}
		}
	}
	if (ball_position.x >= 770.0f) // We might be hit by player 2's paddle
	{
		if (ball_position.y >= (player2_position.y - 10.0f)
				&&
			ball_position.y <= (player2_position.y + 100.0f))
		{
			if (ball_speed.x >= 0) // Ball is moving right
			{
				// Move left and add distance from center of paddle to ball vector
				float distance = player2_position.y + 50.0f - ball_position.y + 5.0f;

				if (ball_position.y + 5.0f < player2_position.y + 50.0f)
					m_ball->setSpeed(sf::Vector2f(ball_speed.x * -1,
								-ball_speed.y - 10*distance));
				else if (ball_position.y + 5.0f >= player2_position.y + 50.0f)
					m_ball->setSpeed(sf::Vector2f(ball_speed.x * -1,
								ball_speed.y - 10*distance));
			}
		}
	}

	// Score if it goes past a paddle
	if (ball_position.x <= 10.0f) // The ball passed player 1's paddle
	{
		// TODO actually score
		// Center the ball
		m_ball->reset(DEFAULT_BALL_SPEED_RIGHT);
	}
	else if (ball_position.x >= 790.0f) // The ball passed player 2's paddle
	{
		// TODO actually score
		m_ball->reset(DEFAULT_BALL_SPEED_LEFT);
	}
}

// Physics step
void Game::step()
{
	handle_collisions();

	const float gravity = 9.81f;
	sf::Vector2f ball_speed = m_ball->getSpeed();

	// Change ball speed according to gravity
	m_ball->setSpeed(sf::Vector2f(ball_speed.x, m_ball->getSpeed().y + (gravity/1.0f)));

	// Actually move the ball
	m_ball->move(m_ball->getSpeed() * m_elapsedTime);
}

// Draws on a RenderWindow
void Game::draw_objects()
{
	// Clear the window
	this->clear();

	// Draw the objects
	this->draw(*m_player1);
	this->draw(*m_player2);
	this->draw(*m_ball);

	// Flip the buffer so we can see what's been drawn on it.
	this->display();
}

void Game::calc_time()
{
	m_elapsedTime = m_clock.getElapsedTime().asSeconds();
	m_clock.restart();
}
