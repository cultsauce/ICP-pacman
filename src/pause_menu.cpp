#include "pause_menu.h"
#include "ui_pause_menu.h"

Pause_menu::Pause_menu(QWidget *parent, QTimer *timer, Game *game) :
    QWidget(parent),
    ui(new Ui::Pause_menu)
{
	this->timer = timer;
	this->game = game;
    ui->setupUi(this);
	timer->stop();
}

Pause_menu::~Pause_menu() {
    delete ui;
}

void Pause_menu::on_pushButton_clicked() {
	this->hide();
	timer->start();
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
