#ifndef QTTEST_GHOST_H
#define QTTEST_GHOST_H
#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Ghost : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Ghost(QGraphicsItem *parent=nullptr);
public slots:
	void move();
private:
	QList<QGraphicsItem *> colliding_items;
	bool left = false;
	QPixmap * pixmap;
};

#endif //QTTEST_GHOST_H
