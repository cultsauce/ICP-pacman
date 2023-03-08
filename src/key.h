#ifndef QTTEST_KEY_H
#define QTTEST_KEY_H

#include <QGraphicsRectItem>
#include <QList>
#include <QTimer>
#include <QGraphicsScene>

class Key : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Key(QGraphicsItem *parent=nullptr, int size=20);
private:
	QPixmap * pixmap;
};

#endif //QTTEST_KEY_H
