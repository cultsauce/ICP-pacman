#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QDebug>
#include <QTransform>

#ifndef QTTEST_GHOST_H
#define QTTEST_GHOST_H

#define GHOST_STEP_SIZE 5

class Ghost : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
    public:
        QList<QPoint> shortest_path;
        QList<QPoint>::iterator s_path_iter;

        Ghost(QGraphicsItem *parent=nullptr, int size=50);
        void move();

    private:
        QList<QGraphicsItem *> colliding_items;
        QPixmap * pixmap;
        QPoint direction;
};

#endif //QTTEST_GHOST_H
