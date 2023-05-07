#ifndef REPLAY_HPP
#define REPLAY_HPP

#include <QList>
#include <QGraphicsScene>
#include <QPoint>
#include <iostream>
#include <fstream>
#include "ghost.hpp"
#include "player.h"

class Replayer {
    private:
        QList <QPoint> player_positions;
        QList <QList <QPoint>> ghost_positions;
        QList <bool> key_positions;
        QList <bool>::iterator key_iter;
        QList <QPoint>::iterator player_iter;
        QList <QList <QPoint>>::iterator ghost_iter;
        QGraphicsScene *parent_scene;
        void read_log_file (std::ifstream &logfile);
        QPoint conv_qpoint (std::string line);

    public:
        Replayer (std::ifstream &logfile);
        QPoint player_next_pos ();
        QPoint player_prev_pos ();

        QList<QPoint> ghost_next_pos ();
        QList<QPoint> ghost_prev_pos ();

        bool key_next_pos ();
        bool key_prev_pos ();
};

#endif //REPLAY_HPP