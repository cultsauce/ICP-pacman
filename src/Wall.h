#ifndef QTTEST_WALL_H
#define QTTEST_WALL_H

#include <QGraphicsRectItem>
#include <QList>
#include <QTimer>
#include <QGraphicsScene>

class Wall : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Wall(QGraphicsItem *parent=nullptr, int size=20);
private:
	QPixmap * pixmap;
};

#endif //QTTEST_WALL_H
