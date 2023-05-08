/// \file victory.hpp
/// \brief This file contains the declaration of the Victory class used for victory screen.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef VICTORY_HPP
#define VICTORY_HPP

#include <QWidget>
#include "game.hpp"

namespace Ui {
class Victory;
}

class Victory : public QWidget {
    Q_OBJECT

    public:
        /// Constructor of the Victory
        /// \param parent parent widget
        /// \param game the game
        explicit Victory(QWidget *parent = nullptr, Game *game = nullptr);

        /// Destructor of the Victory
        ~Victory();

		/// Game
		Game *game;

    public slots:
        /// Handles restart button click
        void on_pushButton_clicked();

        /// Handles exit button click
        void on_pushButton_2_clicked();

    private:
        /// UI of the Victory
        Ui::Victory *ui;
};

#endif // VICTORY_HPP
