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

#include <string>
#include <vector>
#include <fstream>

#include "player.h"
#include "ghost.hpp"
#include "Wall.h"
#include "lock.h"
#include "key.h"

#ifndef SCENE_HPP
#define SCENE_HPP

#define BLOCK_SIZE 50


typedef struct path_node {
    QPoint pos;
    qreal cost;
    qreal heuristic;
    struct path_node *prev_node;
} PathNode;

class GameScene: public QGraphicsScene {
    Q_OBJECT public:
    int width, height;
    GameScene(const char filename[]);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouse_event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
	void set_view(QGraphicsView *view);

    public slots:
    void monitor_game_state ();

    private:
    Player *player;
    std::vector <Ghost *> ghosts;
	QTimer * timer;
	QGraphicsView *view;
    void shortest_path (QPoint start, QPoint stop, QList<QPoint> &path, QList<QPoint>::iterator &iter);
    void generate_scene_from_txt (const char filename []);
    qreal distance_between_points(const QPoint &start, const QPoint &stop);
    void regenerate_path (QList <PathNode *> &closed, PathNode *&start_point, QList <QPoint> &path);
    int contains (QList<PathNode *> open, PathNode *s);
    bool is_valid_move (QPoint &pos);
    QPoint random_pos ();

private slots:
    void log ();
    void game_over ();
    void game_win ();
};

#endif // SCENE_HPP
