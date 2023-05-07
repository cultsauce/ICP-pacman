#ifndef QTTEST_LOCK_H
#define QTTEST_LOCK_H

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

    private:
        /// Pixmap of the lock
        QPixmap * pixmap;
};

#endif //QTTEST_LOCK_H
