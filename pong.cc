#include "game.h"
#include "PongConfig.h"

int main()
{
	// Create the game
	Game game(sf::VideoMode(800,600), "Pong");

	while (game.isOpen())
	{
		// Calculate frametime
		game.calc_time();

		game.handle_events();
		game.step();
		game.draw_objects();
	}

	return 0;
}
