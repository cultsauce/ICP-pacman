#include "key.h"

Key::Key(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("../Resources/images/key.png");
	setPixmap(pixmap->scaled(size, size));
}