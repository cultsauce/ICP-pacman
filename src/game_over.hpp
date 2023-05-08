/// \file game_over.hpp
/// \brief This file contains the declaration of the Game_over class used for game over screen.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef GAME_OVER_HPP
#define GAME_OVER_HPP

#include <QWidget>
#include "game.hpp"

namespace Ui {
class Game_over;
}

class Game_over : public QWidget {
    Q_OBJECT

    public:
        /// Constructor of the game over menu
        /// \param parent parent widget
        /// \param game the game
        explicit Game_over(QWidget *parent = nullptr, Game *game = nullptr);

        /// Destructor of the game over menu
        ~Game_over();

    public slots:
        /// Handles restart button click
        void on_pushButton_clicked();

        /// Handles exit button click
        void on_pushButton_2_clicked();

    private:
        /// UI of the game over menu
        Ui::Game_over *ui;

		/// Game
		Game *game;
};

#endif // GAME_OVER_HPP
