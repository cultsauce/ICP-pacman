#ifndef GAME_OVER_H
#define GAME_OVER_H

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

#endif // GAME_OVER_H
