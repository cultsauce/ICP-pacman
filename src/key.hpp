/// \file key.hpp
/// \brief This file contains the declaration of the Key class used for the key object.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef QTTEST_KEY_HPP
#define QTTEST_KEY_HPP

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

		/// Destructor
		~Key();
    private:
        /// Pixmap of the key
        QPixmap * pixmap;
};

#endif //QTTEST_KEY_HPP
