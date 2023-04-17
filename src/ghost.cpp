#include "ghost.h"
#include "Wall.h"
#include "player.h"
#include <iostream>
#include <QDebug>
#include <QTransform>
#include <math.h>
#include <random>

#define GHOST_STEP_SIZE 5
Ghost::Ghost(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("../Resources/images/ghost.png");
	setPixmap(pixmap->scaled(size, size));

	QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	timer->start(50);

	QTimer * dir_timer = new QTimer(this);
    connect(dir_timer, SIGNAL(timeout()), this, SLOT(set_new_direction()));
	dir_timer->start(2600);
	srand(time(NULL));

	direction.rx() = GHOST_STEP_SIZE;
	direction.ry() = 0;
}

void Ghost::set_new_direction () {
	QTransform transform = QTransform();
	transform.translate( boundingRect().center().x(), boundingRect().center().y());
	
	direction.rx() = 0; direction.ry() = 0;

	while (!direction.rx() && !direction.ry()) {
		int dir = rand() % 4;
		switch (dir) {
			case 0: { /* up */
				if (y() > 5) {
					direction.rx() = 0;
					direction.ry() = -GHOST_STEP_SIZE;
					transform.rotate(-90);
				}
				break;
			}
			case 1: { /* down */
				if (y() < 445) {
					direction.rx() = 0;
					direction.ry() = GHOST_STEP_SIZE;
					transform.rotate(90);
				}
				break;
			}
				
			case 2: { /* right */
				if (x() > 5) {	
					direction.rx() = -GHOST_STEP_SIZE;
					direction.ry() = 0;
					transform.scale(-1, 1);
				}
				break;
			}
			case 3: {/* left */
				if (x() < 445) {
					direction.rx() = GHOST_STEP_SIZE;
					direction.ry() = 0;
					transform.scale(1, 1);
				}
				break;
			}
		}
	}
	
	transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
	setTransform(transform);
}

void Ghost::move() {
	if ((pos().x() > 445 && direction.rx() == GHOST_STEP_SIZE) ||
		(pos().x() < 5 && direction.rx() == -GHOST_STEP_SIZE) || 
		(pos().y() > 445 && direction.ry() == GHOST_STEP_SIZE) ||
		(pos().y() < 5 && direction.ry() == -GHOST_STEP_SIZE)) {
		
		set_new_direction ();
	}
	QList<QGraphicsItem *> items = parent_scene->items(QRectF(x() + direction.rx(), y() + direction.ry(), (qreal)BLOCK_SIZE, (qreal)BLOCK_SIZE));
	for (QGraphicsItem *&item:items) {
		if (typeid(*item) == typeid(Wall)) {
			set_new_direction ();
			return;
		}
	}
	setPos(x() + direction.rx(), y() + direction.ry());
}