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
	this->hide();
	game->option = 1;
	game->restart();
	delete this;
}


void Start::on_pushButton_2_clicked() {
	this->open_file();
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
	std::cout << "open_file" << std::endl;
	QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open File",
          QDir::currentPath(),
          "All files (*.*) ;; Text files (*.txt);; Log files (*.log)");
	if (!filename.isNull()) {
		game->map = filename.toUtf8();
	}
}
