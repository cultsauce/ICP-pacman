/// \file lock.hpp
/// \brief This file contains the declaration of the Lock class used for the lock object.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef QTTEST_LOCK_HPP
#define QTTEST_LOCK_HPP

#include <QGraphicsRectItem>
#include <QList>
#include <QTimer>
#include <QGraphicsScene>

class Lock : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
    public:
        /// Constructor of the lock
        /// \param parent parent item
        /// \param size size of the lock
        Lock(QGraphicsItem *parent=nullptr, int size=20);

		/// Destructor
		~Lock();

    private:
        /// Pixmap of the lock
        QPixmap * pixmap;
};

#endif //QTTEST_LOCK_HPP
