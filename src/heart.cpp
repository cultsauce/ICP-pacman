#include "heart.h"

Heart::Heart(QGraphicsItem *parent, int size) {
	setPixmap(QPixmap("../Resources/images/heart.png").scaled(size, size));
}

Heart::~Heart() {

}
