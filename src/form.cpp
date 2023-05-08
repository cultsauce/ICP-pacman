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
