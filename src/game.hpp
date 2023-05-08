#ifndef GAME_HPP
#define GAME_HPP
class Game;

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QBrush>
#include <QFont>
#include <cmath>
#include <random>
#include <ctime>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "scene.hpp"

class Game {
    public:
        /// Constructor of the game
        /// \param argc number of arguments
        /// \param argv arguments
        /// \param filename file with the map
        Game (int argc, char *argv[], const char filename[]);

		/// Destructor of the game
		~Game ();

        /// Runs the game
        /// \return exit code
        int run ();

		/// Restarts the game
		void restart ();

		/// Starts the game
		void start ();

		/// Leaves the game
		void leave ();

		/// Initializes the game
		int init();

		/// option is 1 if the game is normal mode, 2 if the game is in replay mode
		int option;

		/// Map file name
		const char *map;

    private:
        /// Qt application
        QApplication *app;

        /// Main scene
        GameScene *scene;

        /// Main view
        QGraphicsView *view;

		/// Number of arguments
		int argc;

		/// Arguments
		char **argv;
};
#endif // GAME_HPP
