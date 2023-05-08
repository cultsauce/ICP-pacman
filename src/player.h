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
	Q_OBJECT public:
		/// List of points that the player will follow on mouse click
		QList<QPoint> shortest_path;
		/// Iterator for the list of points
		QList<QPoint>::iterator s_path_iter;

		/// Indicates if the player has found the key
		bool found_key;

		/// Indicates if the player used mouse click to move
		bool follow_path;

		/// Number of lives of the player
		int num_lives;

		/// Number of steps the player has taken
		int step_count;

		/// Indicates if the player is invincible
		bool is_invincible;

		/// Number of ticks the player is invincible for
		int i_ticks;

		/// Constructor
		/// \param parent parent QGraphicsItem
		/// \param size size of the player
		Player(QGraphicsItem *parent=nullptr, int size=50);

		/// Destructor
		~Player();

		/// Moves the player
		void move();

		/// Handles key press events
		void key_move (int key);

		/// Scene of the player
		QGraphicsScene *parent_scene;
	public slots:
		/// Moves the player along the shortest path
		void shortest_path_move ();

	private:
		/// List of colliding items
		QList<QGraphicsItem *> colliding_items;

		/// Direction of the player
		QPoint direction;
};

#endif //QTTEST_PLAYER_H
