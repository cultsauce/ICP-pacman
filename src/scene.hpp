#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QBrush>
#include <QFont>
#include <cmath>

#include <string>
#include <vector>
#include <fstream>
#include "player.h"
#include "ghost.h"
#include "lock.h"
#include "key.h"

#define BLOCK_SIZE 50


typedef struct path_node {
    QPoint pos;
    qreal cost;
    qreal heuristic;
    struct path_node *prev_node;
} PathNode;

class GameScene: public QGraphicsScene {
    Q_OBJECT public:
    GameScene(char filename[]);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouse_event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    bool is_valid_move (QPoint &pos);

    public slots:
    void monitor_game_state ();

    private:
    Player *player;
    std::vector <Ghost *> ghosts;
    void shortest_path (QPoint start, QPoint stop, QList<QPoint> &path, QList<QPoint>::iterator &iter);
    void generate_scene_from_txt (char filename []);
    qreal distance_between_points(const QPoint &start, const QPoint &stop);
    qreal cost_to_point (const QList <PathNode> &open, PathNode &dest);
    void regenerate_path (QList <PathNode *> &closed, PathNode *&start_point, QList <QPoint> &path);
    
    void log ();
    void game_over ();
    void game_win ();
};
