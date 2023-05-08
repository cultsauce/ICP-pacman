#ifndef QTTEST_HEART_H
#define QTTEST_HEART_H

class Heart;

#include <QObject>
#include <QList>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>

#define STEP_SIZE 10
#define BLOCK_SIZE 50

class Heart : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
	/// Constructor
	/// \param parent parent QGraphicsItem
	/// \param size size of the heart
	Heart(QGraphicsItem *parent = nullptr, int size = 50);

	/// Destructor
	~Heart();
};

#endif //QTTEST_HEART_H
