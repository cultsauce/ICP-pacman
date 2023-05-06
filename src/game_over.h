#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QWidget>

namespace Ui {
class Game_over;
}

class Game_over : public QWidget
{
    Q_OBJECT

public:
    explicit Game_over(QWidget *parent = nullptr);
    ~Game_over();

public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Game_over *ui;
};

#endif // GAME_OVER_H
