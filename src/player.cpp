#include "player.h"
#include <iostream>


Player::Player(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("../Resources/images/pacman.png").scaled(size, size));
	direction.rx() = STEP_SIZE;
	direction.ry() = 0;
	found_key = false;
	follow_path = false;
	num_lives = 1;
	step_count = 0;
	i_ticks = 0;
	is_invincible = false;
	this->size = size;
}

Player::~Player() {

}

void Player::move () {
	QTransform transform = QTransform();
	transform.translate( boundingRect().center().x(), boundingRect().center().y());
	if (direction.rx() == -STEP_SIZE) transform.scale(-1, 1);
	else if (direction.rx() == STEP_SIZE) transform.scale(1, 1);
	else if (direction.ry() == -STEP_SIZE) transform.rotate(-90);
	else if (direction.ry() = STEP_SIZE) transform.rotate(90);
	transform.translate( -boundingRect().center().x(),  -boundingRect().center().y());
	setTransform(transform);
	setPos(pos() + direction);
	step_count++;
}

void Player::key_move (int key) {
	follow_path = false;
	if (key == Qt::Key_A) {
		direction.rx() = -STEP_SIZE;
		direction.ry() = 0;
	} 
	else if (key == Qt::Key_D) {
		direction.rx() = STEP_SIZE;
		direction.ry() = 0;
	} 
	else if (key == Qt::Key_W) {
		direction.rx() = 0;
		direction.ry() = -STEP_SIZE;
	} 
	else if (key == Qt::Key_Z) {
		direction.rx() = 0;
		direction.ry() = STEP_SIZE;
	}
	QPointF new_pos = pos() + direction;
	if (new_pos.x() < 0 || new_pos.y() < 0 || new_pos.x() > parent_scene->views().first()->width() - size || new_pos.y() > parent_scene->views().first()->height() - size) return;
	QList<QGraphicsItem *> items = parent_scene->items(QRectF(new_pos.x(), new_pos.y(), (qreal)BLOCK_SIZE, (qreal)BLOCK_SIZE));
	for (QGraphicsItem *&item:items) {
		if (typeid(*item) == typeid(Wall)) {
			return;
		}
	}
	move ();
}

void Player::shortest_path_move () {
	if (pos() == *s_path_iter) s_path_iter = std::next(s_path_iter, 1);
	
	if (s_path_iter == shortest_path.end()) {
		follow_path = false;
		return;
	}
	direction.rx() = 0;
	direction.ry() = 0;
	if ((*s_path_iter).x() > pos().x()) direction.rx() = STEP_SIZE;
	if ((*s_path_iter).x() < pos().x()) direction.rx() = -STEP_SIZE;
	if ((*s_path_iter).y() > pos().y()) direction.ry() = STEP_SIZE;
	if ((*s_path_iter).y() < pos().y()) direction.ry() = -STEP_SIZE;
	move();
}
