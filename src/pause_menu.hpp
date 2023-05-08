/// \file pause_menu.hpp
/// \brief This file contains the declaration of the Pause_menu class used for pause menu.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include <QWidget>
#include <QTimer>
#include "game.hpp"

namespace Ui {
class Pause_menu;
}

class Pause_menu : public QWidget {
    Q_OBJECT

    public:
        /// Constructor of the pause menu
        /// \param parent parent widget
        /// \param timer global timer
        /// \param game the game
        explicit Pause_menu(QWidget *parent = nullptr, QTimer *timer = nullptr, Game *game = nullptr);

        /// Destructor of the pause menu
        ~Pause_menu();

    private:
        /// Global timer
        QTimer *timer;

		/// Game
		Game *game;

    private slots:

        /// Handles resume button click
        void on_pushButton_clicked();

        /// Handles restart button click
        void on_pushButton_2_clicked();

        /// Handles exit button click
        void on_pushButton_3_clicked();

private:
		/// UI of the pause menu
        Ui::Pause_menu *ui;
};

#endif // PAUSE_MENU_H
