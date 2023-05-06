#include "scene.hpp"
#include "menu.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include "form.h"
#include "game_over.h"
#include "pause_menu.h"

GameScene::GameScene (const char filename[]) {
    generate_scene_from_txt (filename);

	log_file.open("log.txt");

    timer = new QTimer(this);
	QTimer * global_timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(monitor_game_state ()));
	timer->start(50);

    srand(time(NULL));
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *mouse_event) {
	if (mouse_event->button () == Qt::LeftButton) {
        int dest_tile_x = static_cast<int>(mouse_event->scenePos().x() / BLOCK_SIZE) * BLOCK_SIZE;
        int dest_tile_y = static_cast<int>(mouse_event->scenePos().y() / BLOCK_SIZE) * BLOCK_SIZE;

        int source_tile_x = static_cast<int>(player->scenePos().x() / BLOCK_SIZE) * BLOCK_SIZE;
        int source_tile_y = static_cast<int>(player->scenePos().y() / BLOCK_SIZE) * BLOCK_SIZE;
        
        QPoint dest = QPoint(dest_tile_x, dest_tile_y);
        QPoint source = QPoint(source_tile_x, source_tile_y);
        if (!is_valid_move(dest)) return;

        shortest_path (source, dest, player->shortest_path, player->s_path_iter);
        player->start_timer ();
	}
	else mouse_event->ignore ();
}

qreal GameScene::distance_between_points (const QPoint &start, const QPoint &stop) {
    return sqrt(pow(stop.x() - start.x(), 2) + pow(stop.y() - start.y(), 2));
}

void GameScene::regenerate_path (QList <PathNode *> &closed, PathNode *&start_point, QList <QPoint> &path) {
    PathNode *tmp = start_point;
    while (tmp != nullptr) {
        path.prepend (tmp->pos);
        tmp = tmp->prev_node;
    }
    qDebug () << "path found";
}

void GameScene::shortest_path (QPoint start, QPoint stop, QList<QPoint> &path, QList<QPoint>::iterator &iter) {
    path.clear ();
    QList <PathNode *> open;
    QList <PathNode *> closed;
    PathNode *current = new PathNode;
    current->pos = start;
    current->prev_node = nullptr;
    current->cost = 0.0;
    current->heuristic = 0.0;
    open.push_back (current);
    while (true) {
        if (open.isEmpty()) {
            qDebug() << "no path found";
            return;
        }
        current = *std::min_element(open.begin(), open.end(), [] ( PathNode *s1, PathNode *s2) {return (s1->heuristic < s2->heuristic);});
        open.removeAt (open.indexOf(current));
        closed.push_back(current);


        if (current->pos == stop) break;
        QList<QPoint> possible_moves;
        possible_moves.push_back(QPoint(current->pos.x()+BLOCK_SIZE, current->pos.y()));
        possible_moves.push_back(QPoint(current->pos.x()-BLOCK_SIZE, current->pos.y()));
        possible_moves.push_back(QPoint(current->pos.x(), current->pos.y()+BLOCK_SIZE));
        possible_moves.push_back(QPoint(current->pos.x(), current->pos.y()-BLOCK_SIZE));

        for (QPoint &move: possible_moves) {
            if (is_valid_move (move)) {
                PathNode *tmp = new PathNode;
                tmp->pos = move;
                tmp->cost = 1.0 + current->cost;
                tmp->heuristic = tmp->cost + distance_between_points(tmp->pos, stop);
                tmp->prev_node = current;

                int closed_idx = contains(closed, tmp);
                if (closed_idx != -1) {
                    delete tmp;
                    continue;
                }
                int open_idx = contains(open, tmp);
                if (open_idx != -1 && open[open_idx]->heuristic > tmp->heuristic) {
                    open.replace (open_idx, tmp);
                }
                else if (open_idx == -1) open.append(tmp);
                else delete tmp;
            }
        }
    }
    regenerate_path (closed, current, path);
    iter = path.begin();
}

bool GameScene::is_valid_move (QPoint &pos) {
    if (pos.x() < 0 || pos.y() < 0 || pos.x() > 450 || pos.y() > 450) return false;
    QGraphicsItem *item = itemAt (pos, QTransform());

    if (item != nullptr && typeid(*item) == typeid(Wall)) return false;
    return true;
}

void GameScene::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_A ||
		event->key() == Qt::Key_D ||
		event->key() == Qt::Key_W ||
		event->key() == Qt::Key_Z	) {

		player->key_move (event->key());
	}
	if (event->key() == Qt::Key_Escape && timer->isActive()) {
		Pause_menu *menu = new Pause_menu(view, timer);
		menu->move(view->width() / 2 - menu->width()/2,view->height() / 2 - menu->height()/2);
		menu->show();
	}
	
}

QPoint GameScene::random_pos () {
    while (true) {
        QPoint pos = QPoint((rand () % width) * BLOCK_SIZE, (rand () % height) * BLOCK_SIZE);
        if (is_valid_move (pos)) return pos;
    }
}

void GameScene::log () {
	log_file << "player: " << player->pos().x() << " " << player->pos().y() << std::endl;
	for (Ghost *ghost: ghosts) {
		log_file << "ghost: " << ghost->pos().x() << " " << ghost->pos().y() << std::endl;
	}
	log_file << "key: " << (player->found_key ? "true" : "false") << std::endl;
	log_file << std::endl;
}

void GameScene::game_over () {
	log_file.close();
	Game_over *form = new Game_over(view);

	form->move(view->width() / 2 - form->width()/2,view->height() / 2 - form->height()/2);
	form->show();
	timer->stop();
}

void GameScene::game_win () {
	log_file.close();
    Form *form = new Form(view);

	form->move(view->width() / 2 - form->width()/2,view->height() / 2 - form->height()/2);
	form->show();
	timer->stop();
}

void GameScene::monitor_game_state () {
    for (Ghost *ghost:ghosts) {
        if (ghost->s_path_iter == ghost->shortest_path.end()) {
            int source_tile_x = static_cast<int>(ghost->scenePos().x() / BLOCK_SIZE) * BLOCK_SIZE;
            int source_tile_y = static_cast<int>(ghost->scenePos().y() / BLOCK_SIZE) * BLOCK_SIZE;
            shortest_path (QPoint(source_tile_x, source_tile_y), random_pos(), ghost->shortest_path, ghost->s_path_iter);
        }
        ghost->move ();
    }
    QList <QGraphicsItem *> intersecting_objects = items (QRectF(player->pos().x(), player->pos().y(), (qreal)BLOCK_SIZE, (qreal)BLOCK_SIZE));
    for (QGraphicsItem *&item: intersecting_objects) {
        if (typeid(*item) == typeid(Ghost)) {
            qDebug() << "gameover";
            game_over ();
        }
        else if (typeid(*item) == typeid(Key)) {
            player->found_key = true;
            removeItem(item);
            delete item;
        }
        else if (typeid(*item) == typeid(Lock) && player->found_key) {
            qDebug () << "winwin";
            game_win ();
        }
    }
    log ();
}

int GameScene::contains(QList<PathNode *> open, PathNode *s) {
    for (int i = 0; i < open.count(); i++) {
        if (open[i]->pos == s->pos) {
            return i;
        }
    }
    return -1;
}

void GameScene::generate_scene_from_txt (const char filename[]) {
    std::ifstream file (filename);
    if (!file.is_open()) {
        exit (EXIT_FAILURE);
    }

    std::string line;
    int i = 0;
    getline(file, line);
    while (isdigit(line[i++]));

    width = atoi(line.substr(0, i).c_str());
    height = atoi(line.substr(i, std::string::npos).c_str());

    this->setSceneRect(0, 0, width * BLOCK_SIZE, height * BLOCK_SIZE);
    this->setBackgroundBrush(QBrush(Qt::black));

    for (i = 0; i < height; i++) {

        if (!getline(file, line) or line.length() != width) exit (EXIT_FAILURE);
        for (int j = 0; j < width; j++) {
            switch (line[j]) {
                case 'S': {
                    player = new Player (nullptr, BLOCK_SIZE);
                    player->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                    player->setFocus();
                    this->addItem(player);
                    player->parent_scene = this;
                    break;
                }
                case 'K': {
                    Key *key = new Key (nullptr, BLOCK_SIZE);
                    key->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    this->addItem(key);
                    break;
                }
                case 'G':{
                    Ghost *ghost = new Ghost (nullptr, BLOCK_SIZE);
					ghosts.push_back(ghost);
                    ghost->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    this->addItem(ghost);
                    break;
                }
                case 'T': {
                    Lock *lock = new Lock (nullptr, BLOCK_SIZE);
                    lock->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    this->addItem(lock);
                    break;
                }
                case 'X': {
                    Wall *wall = new Wall (nullptr, BLOCK_SIZE);
                    wall->setPos(j * BLOCK_SIZE, i * BLOCK_SIZE);
                    this->addItem(wall);
                    break;
                }
                case '.': 
                    break;
                default: exit (EXIT_FAILURE);
            }
        }
    }
    file.close();
}

void GameScene::set_view(QGraphicsView *view) {
	this->view = view;
}
