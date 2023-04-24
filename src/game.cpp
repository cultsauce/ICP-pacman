#include "game.hpp"

Game::Game (int argc, char *argv[], const char filename []) {
    app = new QApplication(argc, argv);
    scene = new GameScene(filename);
}

int Game::run () {
    view = new QGraphicsView (scene);
    view->show();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(scene->width * BLOCK_SIZE, scene->height * BLOCK_SIZE);
    return app->exec();
}