/// \file form.cpp
/// \brief This file contains the implementation of the Form class used for victory screen.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent, Game *game) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
	this->game = game;
}

Form::~Form() {
    delete ui;
}

void Form::on_pushButton_clicked() {
	this->hide();
	game->restart();
	delete this;
    //restart
}

void Form::on_pushButton_2_clicked() {
	exit(0);
}
