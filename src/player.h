#ifndef QTTEST_PLAYER_H
#define QTTEST_PLAYER_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Player : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Player(QGraphicsItem * parent=nullptr);
	void keyPressEvent(QKeyEvent *event) override;
	void move(qreal x, qreal y);
	void spawn();
	void claimKey();
	bool hasKey() const;
private:
	QList<QGraphicsItem *> colliding_items;
	qreal x_last;
	qreal y_last;
	bool holdsKey = false;
};

#endif //QTTEST_PLAYER_H
