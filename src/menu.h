#ifndef QTTEST_MENU_H
#define QTTEST_MENU_H

#include <QApplication>
#include <QGraphicsView>
#include <QWidget>
#include <QMenu>

class Menu : public QMenu {
	Q_OBJECT
public:
	Menu(QWidget *parent = nullptr);
};

#endif //QTTEST_MENU_H
