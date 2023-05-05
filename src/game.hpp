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
        Game (int argc, char *argv[], const char filename[]);
        int run ();
		QPoint location();
    private:
        QApplication *app;
        GameScene *scene;
        QGraphicsView *view;
};
#endif // GAME_HPP
