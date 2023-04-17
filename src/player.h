#ifndef QTTEST_PLAYER_H
#define QTTEST_PLAYER_H

#include "ghost.h"
#include "Wall.h"
#include "key.h"
#include "lock.h"

#include <QObject>
#include <QList>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>


#define STEP_SIZE 10
#define BLOCK_SIZE 50

class Player : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT public:
		QList<QPoint> shortest_path;
		QList<QPoint>::iterator s_path_iter;

		bool found_key;
		int num_lives;

		Player(QGraphicsItem *parent=nullptr, int size=50);
		void move();
		bool start_timer ();
		bool stop_timer ();
		void key_move (int key);
		QGraphicsScene *parent_scene;
	public slots:
		void shortest_path_move ();

	private:
		QList<QGraphicsItem *> colliding_items;
		
		QPoint direction;
		QTimer *path_timer;
};

#endif //QTTEST_PLAYER_H
