#include "player.h"
#include "ghost.h"
#include "Wall.h"
#include "key.h"
#include <QKeyEvent>



Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("../Resources/images/pacman.png").scaled(50, 50));
}


void Player::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Left) {
		move(x() - 10, y());
	} else if (event->key() == Qt::Key_Right) {
		move(x() + 10, y());
	} else if (event->key() == Qt::Key_Up) {
		move(x(), y() - 10);
	} else if (event->key() == Qt::Key_Down) {
		move(x(), y() + 10);
	}
}

void Player::move(qreal x_new, qreal y_new) {
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

void Player::spawn(){ // #spaghetti
    // create an enemy
    Ghost * enemy = new Ghost();
    scene()->addItem(enemy);
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
