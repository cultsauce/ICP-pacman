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
    connect(dir_timer,SIGNAL(timeout()),this,SLOT(set_new_direction()));
	dir_timer->start(2600);
	srand(time(NULL));

	direction[0] = GHOST_STEP_SIZE;
	direction[1] = 0;
}

void Ghost::set_new_direction () {
	QTransform transform = QTransform();
	transform.translate( boundingRect().center().x(), boundingRect().center().y());
	
	direction[0] = 0; direction[1] = 0;

	while (!direction[0] && !direction[1]) {
		int dir = rand() % 4;
		switch (dir) {
			case 0: { /* up */
				if (y() > 5) {
					direction[0] = 0;
					direction[1] = -GHOST_STEP_SIZE;
					transform.rotate(-90);
				}
				break;
			}
			case 1: { /* down */
				if (y() < 445) {
					direction[0] = 0;
					direction[1] = GHOST_STEP_SIZE;
					transform.rotate(90);
				}
				break;
			}
				
			case 2: { /* right */
				if (x() > 5) {	
					direction[0] = -GHOST_STEP_SIZE;
					direction[1] = 0;
					transform.scale(-1, 1);
				}
				break;
			}
			case 3: {/* left */
				if (x() < 445) {
					direction[0] = GHOST_STEP_SIZE;
					direction[1] = 0;
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
	
	
	if ((pos().x() > 445 && direction[0] == GHOST_STEP_SIZE) ||
		(pos().x() < 5 && direction[0] == -GHOST_STEP_SIZE) || 
		(pos().y() > 445 && direction[1] == GHOST_STEP_SIZE) ||
		(pos().y() < 5 && direction[1] == -GHOST_STEP_SIZE)) {
		
		set_new_direction ();
		setPos(x() + direction[0], y() + direction[1]);
	}
	else {
		setPos(x() + direction[0], y() + direction[1]);
	}
	for (auto item : collidingItems()) {
		if (typeid(*item) == typeid(Wall)) {
			setPos(x() - direction[0], y() - direction[1]);
			set_new_direction ();

			break;
			//setPos(x() - direction[0], y() - direction[1]);
		}
		else if (typeid(*item) == typeid(Player)) {
			qDebug() << "Game Over";
			scene()->removeItem(item);
			delete item;
			return;
		}
	}
	
	//  //move ghost left and right
	// if (pos().x() > 450 && !left) {
	// 	left = true;

	// 	/* flip */
	// 	QTransform transform = QTransform();
	// 	transform.translate( boundingRect().center().x(), boundingRect().center().y());
	// 	transform.scale(-1, 1);
	// 	transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
	// 	setTransform(transform);

	// } else if (!left) {
	// 	setPos(x() + 5, y());
	// }

	// if (pos().x() < 0 && left) {
	// 	left = false;
	// 	/* flip */
	// 	QTransform transform = QTransform();
	// 	transform.translate( boundingRect().center().x(), boundingRect().center().y());
	// 	transform.scale(1, 1);
	// 	transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
	// 	setTransform(transform);
		
	// } else if (left) {
	// 	setPos(x() - 5, y());
	// }


}