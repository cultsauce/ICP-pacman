#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Pause_menu;
}

class Pause_menu : public QWidget
{
    Q_OBJECT

public:
    explicit Pause_menu(QWidget *parent = nullptr, QTimer *timer = nullptr);
    ~Pause_menu();

private:
	QTimer *timer;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Pause_menu *ui;
};

#endif // PAUSE_MENU_H
