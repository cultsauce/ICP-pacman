#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QFont>
#include <string>
#include <iostream>
#include <fstream>
#include "player.h"
#include "Wall.h"
#include "key.h"
#include "ghost.h"
#include "lock.h"

#define BLOCK_SIZE 50

class Game {
    public:
        Game (int argc, char *argv[]);
        int run (std::string filename);
    private:
        QApplication *app;
        QGraphicsScene *scene;
        QGraphicsView *view;
        int width, height;
        int generate_scene (std::string filename);
};