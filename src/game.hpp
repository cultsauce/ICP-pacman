#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QFont>

#include <iostream>
#include <fstream>
#include "scene.hpp"

class Game {
    public:
        Game (int argc, char *argv[], char filename[]);
        int run ();
    private:
        QApplication *app;
        GameScene *scene;
        QGraphicsView *view;
};