/// \file pause_menu.cpp
/// \brief This file contains the implementation of the Pause_menu class used for pause menu.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "pause_menu.hpp"
#include "ui_pause_menu.h"

Pause_menu::Pause_menu(QWidget *parent, QTimer *timer, Game *game) :
    QWidget(parent),
    ui(new Ui::Pause_menu)
{
	this->timer = timer;
	this->game = game;
    ui->setupUi(this);
	if (timer != nullptr)
		timer->stop();
}

Pause_menu::~Pause_menu() {
    delete ui;
}

void Pause_menu::on_pushButton_clicked() {
	this->hide();
	if (timer != nullptr) timer->start();
	if (game != nullptr) game->menu_open = false;
	delete this;
    // resume
}

void Pause_menu::on_pushButton_2_clicked() {
	this->hide();
	game->restart();
	delete this;
    //restart
}


void Pause_menu::on_pushButton_3_clicked() {
    exit(0);
}
