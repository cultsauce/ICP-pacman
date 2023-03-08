#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QFont>
#include "player.h"
#include "Wall.h"
#include "key.h"
#include "lock.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  auto scene = new QGraphicsScene();
  scene->setSceneRect(0, 0, 1000, 1000);
  scene->setBackgroundBrush(QBrush(Qt::black));

  auto player = new Player();
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
  player->setPos(500, 800);

  scene->addItem(player);

  auto view = new QGraphicsView(scene);
  view->show();
  view->setFixedSize(1000, 1000);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  player->spawn();

  auto wall = new Wall(nullptr, 100);
  wall->setPos(500, 500);
  scene->addItem(wall);

  auto key = new Key(nullptr, 40);
  key->setPos(400, 500);
  scene->addItem(key);

  auto wall1 = new Wall(nullptr, 100);
  wall1->setPos(300, 500);
  scene->addItem(wall1);

  auto lock = new Lock(nullptr, 40);
  lock->setPos(800, 200);
  scene->addItem(lock);

  return app.exec();
}
