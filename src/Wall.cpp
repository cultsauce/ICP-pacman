#include "Wall.h"

Wall::Wall(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("../Resources/images/wall.jpg");
	setPixmap(pixmap->scaled(size, size));
}