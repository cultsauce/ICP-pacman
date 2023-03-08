#include "ghost.h"
#include "player.h"
#include <iostream>
#include <QDebug>
#include <QTransform>

Ghost::Ghost(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("../Resources/images/ghost.png");
	setPixmap(pixmap->scaled(80, 80));
	QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	timer->start(50);
}

void Ghost::move() {
	for (auto item : collidingItems()) {
		if (typeid(*item) == typeid(Player)) {
			qDebug() << "Game Over";
			scene()->removeItem(item);
			delete item;
			return;
		}
	}

	 //move ghost left and right
	if (pos().x()  > 900 && !left) {
		left = true;
		setPos(x() - 10, y());
		/* flip */
//		QTransform transform = QTransform();
//		transform.scale(-1, 1);
//		setTransform(transform);
	} else if (!left) {
		setPos(x() + 5, y());
	}

	if (pos().x() < 0 && left) {
		left = false;
		setPos(x() + 5, y());
		/* flip */
//		QTransform transform = QTransform();
//		transform.scale(1, 1);
//		setTransform(transform);
	} else if (left) {
		setPos(x() - 5, y());
	}


}