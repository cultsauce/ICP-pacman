#include "ghost.h"
#include "player.h"
#include <iostream>
#include <QDebug>
#include <QTransform>
#include <math.h>

#define BLOCK_SIZE 50
Ghost::Ghost(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("../Resources/images/ghost.png");
	setPixmap(pixmap->scaled(size, size));
	QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	timer->start(50);
}

void Ghost::move() {
	for (auto item : collidingItems()) {
		if (typeid(*item) == typeid(Player)) {
			qDebug() << "Game Over";
			// scene()->removeItem(item);
			// delete item;
			// return;
		}
	}

	 //move ghost left and right
	if (pos().x() > 450 && !left) {
		left = true;

		/* flip */
		QTransform transform = QTransform();
		transform.translate( boundingRect().center().x(), boundingRect().center().y());
		transform.scale(-1, 1);
		transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
		setTransform(transform);

	} else if (!left) {
		setPos(x() + 5, y());
	}

	if (pos().x() < 0 && left) {
		left = false;
		/* flip */
		QTransform transform = QTransform();
		transform.translate( boundingRect().center().x(), boundingRect().center().y());
		transform.scale(1, 1);
		transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
		setTransform(transform);
	} else if (left) {
		setPos(x() - 5, y());
	}


}