#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget {
    Q_OBJECT

    public:
        /// Constructor of the form
        /// \param parent parent widget
        /// \param x x position of the form
        /// \param y y position of the form
        explicit Form(QWidget *parent = nullptr, int x = 0, int y = 0);

        /// Destructor of the form
        ~Form();

    public slots:
        /// Handles restart button click
        void on_pushButton_clicked();

        /// Handles exit button click
        void on_pushButton_2_clicked();

    private:
        /// UI of the form
        Ui::Form *ui;
};

#endif // FORM_H
