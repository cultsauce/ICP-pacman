#ifndef QTTEST_GHOST_H
#define QTTEST_GHOST_H
#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
//#include "scene.hpp"

class Ghost : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT public:
		Ghost(QGraphicsItem *parent=nullptr, int size=50);
		QGraphicsScene *parent_scene;
	public slots:
		void move();
		void set_new_direction ();
	private:
		QList<QGraphicsItem *> colliding_items;
		bool left = false;
		QPixmap * pixmap;
		QPoint direction;
};

#endif //QTTEST_GHOST_H
