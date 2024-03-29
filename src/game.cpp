/// \file game.cpp
/// \brief This file contains the implementation of the Game class used for game management.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "game.hpp"
#include "start.hpp"
#include <QDesktopWidget>
#include <QStyle>

Game::Game (int argc, char *argv[]) {
	this->argc = argc;
	this->argv = argv;
	map = nullptr;
}

int Game::init() {
	option = 0;
	app = new QApplication(argc, argv);
	Start *start = new Start(nullptr, this);
	start->setFixedSize(500, 500);
	start->setGeometry(QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        start->size(),
        qApp->desktop()->availableGeometry()
    ));
	start->show();
	return app->exec();
}

Game::~Game () {
	delete scene;
	delete view;
	delete app;
}

void Game::start() {
	app->setQuitOnLastWindowClosed(true);

	if (app == nullptr) app = new QApplication(argc, argv);

	if (option == 1) {
		scene = new GameScene(map, this, false, true, false);
	} else if (option == 2) {
		scene = new GameScene(map, this, false, false, true);
	} else {
		app->exit(1);
	}
}

int Game::run () {
    view = new QGraphicsView (scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(scene->width * BLOCK_SIZE, scene->height * BLOCK_SIZE);
	view->setWindowTitle("Pacman");
	view->setGeometry(QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        view->size(),
        qApp->desktop()->availableGeometry()
    ));
	scene->set_view(view);
	view->show();
    return app->exec();
}

void Game::restart () {
	app->setQuitOnLastWindowClosed(false);
	app->closeAllWindows();
	app->exit(5);
}

void Game::leave() {
	app->closeAllWindows();
}
