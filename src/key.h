/// \file key.h
/// \brief This file contains the declaration of the Key class used for the key object.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef QTTEST_KEY_H
#define QTTEST_KEY_H

#include <QGraphicsRectItem>
#include <QList>
#include <QTimer>
#include <QGraphicsScene>

class Key : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
    public:
        /// Constructor of the key
        /// \param parent parent item
        /// \param size size of the key
        Key(QGraphicsItem *parent=nullptr, int size=20);
    private:
        /// Pixmap of the key
        QPixmap * pixmap;
};

#endif //QTTEST_KEY_H
