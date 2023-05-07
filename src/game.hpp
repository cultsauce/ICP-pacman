#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QFont>

#include <iostream>
#include <fstream>
#include "scene.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class Game {
    public:
        /// Constructor of the game
        /// \param argc number of arguments
        /// \param argv arguments
        /// \param filename file with the map
        Game (int argc, char *argv[], const char filename[]);

        /// Runs the game
        /// \return exit code
        int run ();

    private:
        /// Qt application
        QApplication *app;

        /// Main scene
        GameScene *scene;

        /// Main view
        QGraphicsView *view;
};
#endif // GAME_HPP
