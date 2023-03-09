#ifndef QTTEST_PLAYER_H
#define QTTEST_PLAYER_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#define STEP_SIZE 10
class Player : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT public:
		Player(QGraphicsItem * parent=nullptr, int size=50);
		void keyPressEvent(QKeyEvent *event) override;
		void move(qreal x, qreal y);
		void claimKey();
		bool hasKey() const;
	private:
		QList<QGraphicsItem *> colliding_items;
		qreal x_last;
		qreal y_last;
		bool holdsKey = false;
};

#endif //QTTEST_PLAYER_H
