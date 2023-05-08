/// \file heart.cpp
/// \brief This file contains the implementation of the Heart class used for live count gui.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "heart.h"

Heart::Heart(QGraphicsItem *parent, int size) {
	setPixmap(QPixmap("Resources/images/heart.png").scaled(size, size));
}

Heart::~Heart() {

}
