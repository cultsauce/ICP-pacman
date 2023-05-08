/// \file Wall.hpp
/// \brief This file contains the declaration of the Wall class used for the walls in the game.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef QTTEST_WALL_HPP
#define QTTEST_WALL_HPP

#include <QGraphicsRectItem>
#include <QList>
#include <QTimer>
#include <QGraphicsScene>

class Wall : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
    public:
        /// Constructor of the wall
        /// \param parent parent item
        /// \param size size of the wall
        Wall(QGraphicsItem *parent=nullptr, int size=50);

		/// Destructor of the wall
		~Wall();
    private:
        /// Pixmap of the wall
        QPixmap * pixmap;
};

#endif //QTTEST_WALL_HPP
