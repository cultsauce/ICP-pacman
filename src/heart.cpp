/// \file heart.cpp
/// \brief This file contains the implementation of the Heart class used for live count gui.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "heart.hpp"

Heart::Heart(QGraphicsItem *parent, int size) {
	pixmap = new QPixmap("Resources/images/heart.png");
	setPixmap(pixmap->scaled(size, size));
}

Heart::~Heart() {
	delete pixmap;
}
