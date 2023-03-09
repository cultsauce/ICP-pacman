#ifndef QTTEST_LOCK_H
#define QTTEST_LOCK_H

#include <QGraphicsRectItem>
#include <QList>
#include <QTimer>
#include <QGraphicsScene>

class Lock : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT public:
		Lock(QGraphicsItem *parent=nullptr, int size=20);
	public slots:
		void open();
	private:
		QList<QGraphicsItem *> colliding_items;
		QPixmap * pixmap;
};

#endif //QTTEST_LOCK_H
