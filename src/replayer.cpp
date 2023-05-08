/// \file replayer.cpp
/// \brief This file contains the implementation of the Replayer class used for replaying the game.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "replayer.hpp"

Replayer::Replayer (std::ifstream &logfile) {
    player_positions.clear ();
    ghost_positions.clear ();
    key_positions.clear();
    read_log_file (logfile);
    player_iter = player_positions.begin ();
    ghost_iter = ghost_positions.begin ();
    key_iter = key_positions.begin ();
}

QPoint Replayer::player_next_pos () {
    if (std::next(player_iter, 1) != player_positions.end()) {
        player_iter = std::next(player_iter, 1);
    }
    return *player_iter;
}   

QPoint Replayer::player_prev_pos () {
    if (player_iter != player_positions.begin()) {
        player_iter = std::prev(player_iter, 1);
    }
    return *player_iter;
}

bool Replayer::key_prev_pos () {
    if (key_iter != key_positions.begin()) {
        key_iter = std::prev(key_iter, 1);
    }
    return *key_iter;
}
bool Replayer::key_next_pos () {
    if (std::next(key_iter, 1) != key_positions.end()) {
        key_iter = std::next(key_iter, 1);
    }
    return *key_iter;
}  

QList<QPoint> Replayer::ghost_prev_pos () {
    if (ghost_iter != ghost_positions.begin()) {
        ghost_iter = std::prev(ghost_iter, 1);
    }
    return *ghost_iter;
}

QList<QPoint> Replayer::ghost_next_pos () {
    if (std::next(ghost_iter, 1) != ghost_positions.end()) {
        ghost_iter = std::next(ghost_iter, 1);
    }
    return *ghost_iter;
}

QPoint Replayer::conv_qpoint (std::string line) {
    int ws1_idx = line.find (' ');
    int ws2_idx = line.find (' ', ws1_idx+1);
   
    int x = std::stoi (line.substr(ws1_idx, ws2_idx-ws1_idx));
    int y = std::stoi (line.substr(ws2_idx, std::string::npos));
    QPoint coord = QPoint (x, y);
    return coord;
}

void Replayer::read_log_file (std::ifstream &logfile) {
    std::string line;
    if (!logfile.is_open()) exit(EXIT_FAILURE);
    while (getline (logfile, line)) {
        if (line.length() == 0) ghost_positions.push_back (QList<QPoint> ());
        else if (line.find ("p ") == 0) {
            player_positions.push_back (conv_qpoint (line));
        }
        else if (line.find ("g ") == 0) {
            ghost_positions.last().push_back (conv_qpoint (line));
        }
        else if (line.find ("k false") == 0) {
            key_positions.push_back(false);
        }
        else if (line.find ("k true") == 0) {
            key_positions.push_back(true);
        }
    }
    ghost_positions.pop_back ();
}
