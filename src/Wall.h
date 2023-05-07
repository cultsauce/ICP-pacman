#ifndef QTTEST_WALL_H
#define QTTEST_WALL_H

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
    private:
        /// Pixmap of the wall
        QPixmap * pixmap;
};

#endif //QTTEST_WALL_H
