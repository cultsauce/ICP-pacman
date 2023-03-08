#include "lock.h"
#include "player.h"
#include <QDebug>
#include <QApplication>

Lock::Lock(QGraphicsItem *parent, int size): QGraphicsPixmapItem(parent) {
	pixmap = new QPixmap("../Resources/images/lock.png");
	setPixmap(pixmap->scaled(size, size));
	QTimer * timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(open()));
	timer->start(50);
}

void Lock::open() {
	QList<QGraphicsItem *> colliding_items = collidingItems();
	for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
			QDebug(QtMsgType::QtDebugMsg) << "You win!";
            return;
        }
    }
}