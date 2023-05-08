/// \file ghost.cpp
/// \brief This file contains the implementation of the Ghost class used for ghost enemies.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "ghost.hpp"

Ghost::Ghost(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("Resources/images/ghost.png");
	setPixmap(pixmap->scaled(size, size));

	direction.rx() = 0;
	direction.ry() = 0;

	shortest_path.clear();
	s_path_iter = shortest_path.end();
}

Ghost::~Ghost() {
	delete pixmap;
}

void Ghost::move() {
	if (pos() == *s_path_iter) s_path_iter = std::next(s_path_iter, 1);
	
	if (s_path_iter == shortest_path.end()) {
		return;
	}
	direction.rx() = 0;
	direction.ry() = 0;
	if ((*s_path_iter).x() > pos().x()) direction.rx() = GHOST_STEP_SIZE;
	if ((*s_path_iter).x() < pos().x()) direction.rx() = -GHOST_STEP_SIZE;
	if ((*s_path_iter).y() > pos().y()) direction.ry() = GHOST_STEP_SIZE;
	if ((*s_path_iter).y() < pos().y()) direction.ry() = -GHOST_STEP_SIZE;

	QTransform transform = QTransform();
	transform.translate( boundingRect().center().x(), boundingRect().center().y());
	if (direction.rx() == -GHOST_STEP_SIZE) transform.scale(-1, 1);
	else if (direction.rx() == GHOST_STEP_SIZE) transform.scale(1, 1);
	else if (direction.ry() == -GHOST_STEP_SIZE) transform.rotate(-90);
	else if (direction.ry() = GHOST_STEP_SIZE) transform.rotate(90);
	transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
	setTransform(transform);
	setPos(pos() + direction);
}
