/// \file lock.cpp
/// \brief This file contains the implementation of the Lock class used for the lock object.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "lock.hpp"
#include "player.hpp"
#include <QDebug>
#include <QApplication>

Lock::Lock(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("Resources/images/lock.png");
	setPixmap(pixmap->scaled(size, size));
}

Lock::~Lock() {
	delete pixmap;
}
