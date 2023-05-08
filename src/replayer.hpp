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
		/// List of player positions
        QList <QPoint> player_positions;

		/// List of ghost positions
        QList <QList <QPoint>> ghost_positions;

		/// List of key positions
        QList <bool> key_positions;

		/// Iterator for the list of key positions
        QList <bool>::iterator key_iter;

		/// Iterator for the list of player positions
        QList <QPoint>::iterator player_iter;

		/// Iterator for the list of ghost positions
        QList <QList <QPoint>>::iterator ghost_iter;

		/// Reads the log file
		/// \param logfile file stream of the log file
        void read_log_file (std::ifstream &logfile);

		/// Converts a string to a QPoint
		/// \param line string to be converted
		/// \return QPoint
        QPoint conv_qpoint (std::string line);

    public:
		/// Constructor
		/// \param logfile file stream of the log file
        Replayer (std::ifstream &logfile);

		/// Sets the next position of the player
		/// \return QPoint indicating the next position
        QPoint player_next_pos ();

		/// Sets the previous position of the player
		/// \return QPoint indicating the previous position
        QPoint player_prev_pos ();

		/// Sets the next position of the ghosts
		/// \return QList<QPoint> indicating the next positions
        QList<QPoint> ghost_next_pos ();

		/// Sets the previous position of the ghosts
		/// \return QList<QPoint> indicating the previous positions
        QList<QPoint> ghost_prev_pos ();

		/// Sets the next position of the key
		/// \return bool indicating the next position
        bool key_next_pos ();

		/// Sets the previous position of the key
		/// \return bool indicating the previous position
        bool key_prev_pos ();
};

#endif //REPLAY_HPP
