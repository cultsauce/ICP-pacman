/// \file start.cpp
/// \brief This file contains the implementation of the Start class used for the start menu.
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#include "start.h"
#include "ui_start.h"
#include "game.hpp"

Start::Start(QWidget *parent, Game *game) :
    QWidget(parent),
    ui(new Ui::Start)
{
	this->game = game;
    ui->setupUi(this);
}

Start::~Start() {
    delete ui;
}

void Start::on_pushButton_clicked() {
	this->open_file();
	if (game->map == nullptr) {
		return;
	}
	this->hide();
	game->option = 1;
	game->restart();
	delete this;
}


void Start::on_pushButton_2_clicked() {
	this->open_file();
	if (game->map == nullptr) {
		return;
	}

	this->hide();
	game->option = 2;
	game->restart();
	delete this;
}


void Start::on_pushButton_3_clicked() {
	game->leave();
	delete this;
}

void Start::open_file() {
	QString filename = nullptr;
	filename =  QFileDialog::getOpenFileName(
          this,
          "Open File",
          QDir::currentPath(),
          "All files (*.*) ;; Text files (*.txt);; Log files (*.log)"
    );
	if (!filename.isNull()) {
		std::string *wtf = new std::string (filename.toUtf8().constData());
		game->map = wtf->c_str();
	}
}
