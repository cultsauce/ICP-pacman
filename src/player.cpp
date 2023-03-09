#include "player.h"
#include "ghost.h"
#include "Wall.h"
#include "key.h"
#include <QKeyEvent>



Player::Player(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("../Resources/images/pacman.png").scaled(size, size));
}


void Player::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_A) {
		move(x() - STEP_SIZE, y());
	} else if (event->key() == Qt::Key_S) {
		move(x() + STEP_SIZE, y());
	} else if (event->key() == Qt::Key_W) {
		move(x(), y() - STEP_SIZE);
	} else if (event->key() == Qt::Key_Z) {
		move(x(), y() + STEP_SIZE);
	}
}

void Player::move(qreal x_new, qreal y_new) {
	if (x_new < 0 || y_new < 0 || x_new >= 455 || y_new >= 455) return;
	x_last = x();
	y_last = y();
	setPos(x_new, y_new);
	claimKey();
	for (auto const item : collidingItems()) {
		if (typeid(*item) == typeid(Wall)) {
			setPos(x_last, y_last);
			return;
		}
	}
}

void Player::claimKey() {
	for (auto const item : collidingItems()) {
		if (typeid(*item) == typeid(Key)) {
			holdsKey = true;
			scene()->removeItem(item);
			delete item;
			return;
		}
	}
}

bool Player::hasKey() const {
	return holdsKey;
}
