/// \file victory.cpp
/// \brief This file contains the implementation of the Victory class used for victory screen.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "victory.hpp"
#include "ui_victory.h"

Victory::Victory(QWidget *parent, Game *game) :
    QWidget(parent),
    ui(new Ui::Victory)
{
    ui->setupUi(this);
	this->game = game;
}

Victory::~Victory() {
    delete ui;
}

void Victory::on_pushButton_clicked() {
	this->hide();
	game->restart();
	delete this;
    //restart
}

void Victory::on_pushButton_2_clicked() {
	exit(0);
}
