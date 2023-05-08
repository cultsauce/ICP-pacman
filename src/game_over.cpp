/// \file game_over.cpp
/// \brief This file contains the implementation of the Game_over class used for game over screen.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "game_over.h"
#include "ui_game_over.h"

Game_over::Game_over(QWidget *parent, Game *game) :
    QWidget(parent),
    ui(new Ui::Game_over)
{
    ui->setupUi(this);
}

Game_over::~Game_over() {
    delete ui;
}

void Game_over::on_pushButton_clicked() {
	this->hide();
	delete this;
	game->restart();
}

void Game_over::on_pushButton_2_clicked() {
    exit(0);
}
