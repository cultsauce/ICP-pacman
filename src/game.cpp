#include "game.hpp"

Game::Game (int argc, char *argv[], char filename []) {
    app = new QApplication(argc, argv);
    scene = new GameScene(filename);
}

int Game::run () {
    view = new QGraphicsView (scene);
    view->show();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(10 * BLOCK_SIZE, 10 * BLOCK_SIZE);
    return app->exec();
}