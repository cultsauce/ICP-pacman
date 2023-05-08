/// \file game.hpp
/// \brief This file contains the declaration of the Game class used for game management.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

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
        Game (int argc, char *argv[]);

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

		/// menu_open is true if the menu is open
		/// indicate if menu is already open
		bool menu_open;

		/// Filename of the map
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
