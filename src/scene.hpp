#ifndef SCENE_HPP
#define SCENE_HPP

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QBrush>
#include <QFont>
#include <cmath>
#include <random>
#include <ctime>

#include <string>
#include <vector>
#include <fstream>

#include "player.h"
#include "ghost.hpp"
#include "Wall.h"
#include "lock.h"
#include "key.h"
#include "pause_menu.h"
#include "replayer.hpp"



#define BLOCK_SIZE 50


typedef struct path_node {
    QPoint pos;
    qreal cost;
    qreal heuristic;
    struct path_node *prev_node;
} PathNode;


class GameScene: public QGraphicsScene {
<<<<<<< HEAD
    Q_OBJECT public:
    int width, height;
    bool replay_mode;
    GameScene(const char filename[]);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouse_event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
	void set_view(QGraphicsView *view);
=======
    Q_OBJECT
    public:
        /// Width of the scene from the map
        int width;

        /// Height of the scene from the map
        int height;

        /// Constructor of the main scene
        /// \param filename file with the map
        GameScene(const char filename[]);

        /// Destructor of the main scene
        ~GameScene();

        /// Handles mouse click events
        /// \param mouse_event Qt mouse event
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouse_event) override;

        /// Handles key press events
        /// \param event Qt key event
        virtual void keyPressEvent(QKeyEvent *event) override;

        /// Sets the view of the scene
        /// \param view pointer to the view
        void set_view(QGraphicsView *view);
>>>>>>> f548508cc74547ba59c14f2de0dffd6e0cd42182

    public slots:
        /// Monitors the game state
        void monitor_game_state ();

    private:
<<<<<<< HEAD
    Player *player;
    Key *key;
    std::vector <Ghost *> ghosts;
    Replayer *replayer;
	QTimer * timer;
	QGraphicsView *view;
	std::ofstream log_file;

    void log ();
    void regenerate_path (QList <PathNode *> &closed, PathNode *&start_point, QList <QPoint> &path);
    void shortest_path (QPoint start, QPoint stop, QList<QPoint> &path, QList<QPoint>::iterator &iter);
    void generate_scene_from_txt (std::ifstream &file);
    qreal distance_between_points(const QPoint &start, const QPoint &stop);
    QPoint random_pos ();
    int contains (QList<PathNode *> open, PathNode *s);
    bool is_valid_move (QPoint &pos);
    void replay (const char log_file[]);

private slots:
    void game_over ();
    void game_win ();
=======
        /// Player of the game
        Player *player;

        /// Vector of ghosts
        std::vector <Ghost *> ghosts;

        /// Global timer
        QTimer * timer;

        /// View of the scene
        QGraphicsView *view;

        /// Logging file
        std::ofstream log_file;

        /// Logs the game state
        void log ();

        /// Recalculates the path
        /// \param closed closed nodes
        /// \param start_point starting point
        /// \param path resulting path
        void regenerate_path (QList <PathNode *> &closed, PathNode *&start_point, QList <QPoint> &path);

        /// Finds the shortest path
        /// \param start starting point
        /// \param stop ending point
        /// \param path resulting path
        /// \param iter iterator to the path
        void shortest_path (QPoint start, QPoint stop, QList<QPoint> &path, QList<QPoint>::iterator &iter);

        /// Generates the scene from a text file
        /// \param filename file with the map
        void generate_scene_from_txt (const char filename []);

        /// Calculates the distance between two points
        /// \param start starting point
        /// \param stop ending point
        /// \return distance between the points
        qreal distance_between_points(const QPoint &start, const QPoint &stop);

        /// Generates a random position
        QPoint random_pos ();

        /// Checks if a point is in a list
        /// \param open list of points
        /// \param s point to check
        int contains (QList<PathNode *> open, PathNode *s);

        /// Checks if a point is valid
        /// \param pos point to check
        bool is_valid_move (QPoint &pos);

    private slots:
        /// Handles the game over event
        void game_over ();
        /// Handles the game win event
        void game_win ();
>>>>>>> f548508cc74547ba59c14f2de0dffd6e0cd42182
};

#endif // SCENE_HPP
