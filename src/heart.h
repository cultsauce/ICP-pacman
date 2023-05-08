/// \file heart.h
/// \brief This file contains the declaration of the Heart class used for live count gui.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

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
