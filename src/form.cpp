#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent, int x, int y) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form() {
    delete ui;
}

void Form::on_pushButton_clicked() {
	exit(1);
}

void Form::on_pushButton_2_clicked() {
	exit(0);
}
