/// \file Wall.cpp
/// \brief This file contains the implementation of the Wall class used for the walls in the game.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "Wall.h"

Wall::Wall(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("Resources/images/wall.jpg");
	setPixmap(pixmap->scaled(size, size));
}

Wall::~Wall() {
	delete pixmap;
}
