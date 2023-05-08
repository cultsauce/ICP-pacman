#include "game.hpp"


int main(int argc, char *argv[]) {
	Game *game = new Game (argc, argv, "map.txt");
	int ret = game->init();
	if (ret != 5) return ret;
	while (true) {
		game->start();
		ret = game->run();
		if (ret != 5) return ret;
		game->restart();
	}
}
