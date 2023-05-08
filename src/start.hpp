/// \file start.hpp
/// \brief This file contains the declaration of the Start class used for start menu.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef START_HPP
#define START_HPP

#include <QWidget>
#include "game.hpp"
#include <QFileDialog>

namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

	public:
		/// Constructor of the start menu
		/// \param parent parent widget
		/// \param game the game
	    explicit Start(QWidget *parent = nullptr, Game *game = nullptr);

		/// Destructor of the start menu
	    ~Start();

		/// Opens a file
		void open_file();

		/// Game
		Game *game;

	private slots:

		/// Handles New Game button click
	    void on_pushButton_clicked();

		/// Handles Replay button click
	    void on_pushButton_2_clicked();

		/// Handles Exit button click
	    void on_pushButton_3_clicked();

	private:
		/// UI of the start menu
	    Ui::Start *ui;

		QString map;
};

#endif // START_HPP
