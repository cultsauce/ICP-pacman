#include "player.h"
#include "ghost.h"
#include "Wall.h"
#include "key.h"
#include <QKeyEvent>
#include <QMouseEvent>


#define BLOCK_SIZE 50

Player::Player(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("../Resources/images/pacman.png").scaled(size, size));
	direction[0] = STEP_SIZE;
	direction[1] = 0;
}

void Player::keyPressEvent(QKeyEvent *event) {
	QTransform transform = QTransform();
	transform.translate( boundingRect().center().x(), boundingRect().center().y());
	if (event->key() == Qt::Key_A) {
		direction[0] = -STEP_SIZE;
		direction[1] = 0;
		transform.scale(-1, 1);
	} 
	else if (event->key() == Qt::Key_S) {
		direction[0] = STEP_SIZE;
		direction[1] = 0;
		transform.scale(1, 1);
	} 
	else if (event->key() == Qt::Key_W) {
		direction[0] = 0;
		direction[1] = -STEP_SIZE;
		transform.rotate(-90);
	} 
	else if (event->key() == Qt::Key_Z) {
		direction[0] = 0;
		direction[1] = STEP_SIZE;
		transform.rotate(90);
	}
	transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
	setTransform(transform);
	move(x() + direction[0], y() + direction[1]);
}

void Player::move(qreal x_new, qreal y_new) {
	if (x_new < 0 || y_new < 0 || x_new > 450 || y_new > 450) return;
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
