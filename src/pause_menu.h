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
        /// Constructor of the pause menu
        /// \param parent parent widget
        /// \param timer global timer
        explicit Pause_menu(QWidget *parent = nullptr, QTimer *timer = nullptr);

        /// Destructor of the pause menu
        ~Pause_menu();

    private:
        /// Global timer
        QTimer *timer;

    private slots:

        /// Handles resume button click
        void on_pushButton_clicked();

        /// Handles replay button click
        void on_pushButton_2_clicked();

        /// Handles restart button click
        void on_pushButton_3_clicked();

        /// Handles exit button click
        void on_pushButton_4_clicked();

    private:
        Ui::Pause_menu *ui;
};

#endif // PAUSE_MENU_H
