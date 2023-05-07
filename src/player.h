#ifndef QTTEST_PLAYER_H
#define QTTEST_PLAYER_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>

#include "Wall.h"

#define STEP_SIZE 10
#define BLOCK_SIZE 50

class Player : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
    public:
        /// List of points of the shortest path
        QList<QPoint> shortest_path;

        /// Iterator of the shortest path
        QList<QPoint>::iterator s_path_iter;

        /// Scene of the game
        QGraphicsScene *parent_scene;

        /// Boolean to check if the player has the key
        bool found_key;

        /// Number of lives of the player
        int num_lives;

        /// Constructor of the player
        /// \param parent parent item
        /// \param size size of the player
        Player(QGraphicsItem *parent=nullptr, int size=50);

        /// Move the player
        void move();

        /// Start the timer
        bool start_timer ();

        /// Stop the timer
        bool stop_timer ();

        /// Move the player according to the key pressed
        /// \param key key pressed
        void key_move (int key);

    public slots:
        /// Move the player according to the shortest path
        void shortest_path_move ();

    private:
        /// List of items colliding with the player
        QList<QGraphicsItem *> colliding_items;

        /// Direction of the player
        QPoint direction;

        /// Timer for the shortest path
        QTimer *path_timer;
};

#endif //QTTEST_PLAYER_H
