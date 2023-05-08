#ifndef QTTEST_GHOST_H
#define QTTEST_GHOST_H
class Ghost;

#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QDebug>
#include <QTransform>

#define GHOST_STEP_SIZE 5

class Ghost : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
    public:
		/// List of points that the ghost will follow
        QList<QPoint> shortest_path;
		/// Iterator for the list of points
        QList<QPoint>::iterator s_path_iter;

		/// Constructor
		/// \param parent parent QGraphicsItem
		/// \param size size of the ghost
        Ghost(QGraphicsItem *parent=nullptr, int size=50);

		/// Destructor
		~Ghost();

		/// Moves the ghost
        void move();

    private:
		/// List of colliding items
        QList<QGraphicsItem *> colliding_items;

		/// Pixmap of the ghost
        QPixmap * pixmap;

		/// Direction of the ghost
        QPoint direction;
};

#endif //QTTEST_GHOST_H
