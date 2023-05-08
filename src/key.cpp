/// \file key.cpp
/// \brief This file contains the implementation of the Key class used for the key object.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "key.hpp"

Key::Key(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("Resources/images/key.png");
	setPixmap(pixmap->scaled(size, size));
}

Key::~Key() {
	delete pixmap;
}
