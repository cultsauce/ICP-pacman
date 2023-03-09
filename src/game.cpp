#include "game.hpp"

Game::Game (int argc, char *argv[]) {
    app = new QApplication(argc, argv);
    scene = new QGraphicsScene();
}

int Game::generate_scene (std::string filename) {
    std::ifstream file (filename);
    if (!file.is_open()) 
        exit (EXIT_FAILURE);

    std::string line;
    int i = 0;
    getline(file, line);
    while (isdigit(line[i++]));

    width = atoi(line.substr(0, i).c_str());
    height = atoi(line.substr(i, std::string::npos).c_str());

    scene->setSceneRect(0, 0, width * BLOCK_SIZE, height * BLOCK_SIZE);
    scene->setBackgroundBrush(QBrush(Qt::black));

    for (i = 0; i < height; i++) {

        if (!getline(file, line)) exit (EXIT_FAILURE);
        for (int j = 0; j < width; j++) {
            switch (line[j]) {
                case 'S': {
                    Player *player = new Player ();
                    player->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    player->setFlag(QGraphicsItem::ItemIsFocusable);
                    player->setFocus();
                    scene->addItem(player);
                    break;
                }
                case 'K': {
                    Key *key = new Key (nullptr, BLOCK_SIZE);
                    key->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    scene->addItem(key);
                    break;
                }
                case 'G':{
                    Ghost *ghost = new Ghost ();
                    ghost->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    scene->addItem(ghost);
                    break;
                }
                case 'T': {
                    Lock *lock = new Lock (nullptr, BLOCK_SIZE);
                    lock->setPos(j *BLOCK_SIZE, i *BLOCK_SIZE);
                    scene->addItem(lock);
                    break;
                }
                case 'X': {
                    Wall *wall = new Wall ();
                    wall->setPos(j * BLOCK_SIZE, i * BLOCK_SIZE);
                    scene->addItem(wall);
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

int Game::run (std::string filename) {
    generate_scene (filename);

    view = new QGraphicsView (scene);
    view->show();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(width * BLOCK_SIZE, height * BLOCK_SIZE);

    return app->exec();
}