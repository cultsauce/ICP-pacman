/// \file main.cpp
/// \brief This file contains the implementation of the main function.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "game.hpp"


int main(int argc, char *argv[]) {
	Game *game = new Game (argc, argv);
	int ret = game->init();
	if (ret != 5) return ret;
	while (true) {
		game->start();
		ret = game->run();
		if (ret != 5) break;
		game->restart();
	}
	delete game;
	return ret;
}
