#include "pacman.hpp"


Pacman::Pacman (char *filename) {
    pacman = nullptr;
    key = nullptr;
    ghosts = nullptr;
    num_ghosts = 0;
    end = nullptr;

    srand(time(NULL));

    std::ifstream file (filename);
    std::string line;
    int i = 0;
    getline(file, line);
    while (isdigit(line[i++]));
    int m = atoi(line.substr(0, i).c_str());
    int n = atoi(line.substr(i, std::string::npos).c_str());

    new_field = new Field (m, n);

    for (i = 0; i < m; i++) {

        if (!getline(file, line)) exit (EXIT_FAILURE);
        for (int j = 0; j < n; j++) {

            Block *tmp = new_field->get_block(j, i);
            tmp->x = j; tmp->y = i;
            switch (line[j]) {
                case 'S': 
                    tmp->set_type(PACMAN);
                    pacman = tmp; 
                    break;
                case 'K': 
                    tmp->set_type(KEY);
                    key = tmp; 
                    break;
                case 'G':
                    tmp->set_type(GHOST); 
                    add_ghost(tmp); 
                    break;
                case 'T': 
                    tmp->set_type(END); 
                    end = tmp; 
                    break;
                case 'X': 
                    tmp->set_type(WALL);
                    break;
                case '.': 
                    tmp->set_type(GROUND); 
                    break;
                default: exit (EXIT_FAILURE);
            }
        }
    }
}

Pacman::~Pacman() {
}

void Pacman::display () {
    for (int i = 0; i < new_field->height; i++) {
        for (int j = 0; j < new_field->width; j++) {
            Block *tmp = new_field->get_block(j, i);
            std::cout << sprites[tmp->get_type()];
        }
        std::cout << std::endl;
    }
}

void Pacman::move_self (char in) {
    pacman->set_type(GROUND);
    switch (in) {
        case 'w':
            if (pacman->y > 0 && new_field->get_block(pacman->x, pacman->y-1)->get_type() != WALL) {
                pacman = new_field->get_block(pacman->x, pacman->y-1);
            }
            break;
        case 'a':
            if (pacman->x > 0 && new_field->get_block(pacman->x-1, pacman->y)->get_type() != WALL) {
                pacman = new_field->get_block(pacman->x-1, pacman->y);
            }
            break;
        case 's':
            if (pacman->x < new_field->width-1 && new_field->get_block(pacman->x+1, pacman->y)->get_type() != WALL) {
                pacman = new_field->get_block(pacman->x+1, pacman->y);
            }
            break;
        case 'z':
            if (pacman->y < new_field->height-1 && new_field->get_block(pacman->x, pacman->y+1)->get_type() != WALL) {
                pacman = new_field->get_block(pacman->x, pacman->y+1);
            }
            break;
    }
    pacman->set_type(PACMAN);
}


void Pacman::move_ghosts () {
    for (int i = 0; i < num_ghosts; i++) {
        ghosts[i]->set_type(GROUND);

        /* 4 way movement options */
        Block *positions[] = {
                                new_field->get_block(ghosts[i]->x-1, ghosts[i]->y),
                                new_field->get_block(ghosts[i]->x+1, ghosts[i]->y),
                                new_field->get_block(ghosts[i]->x, ghosts[i]->y+1),
                                new_field->get_block(ghosts[i]->x, ghosts[i]->y-1)
                            };
        int pos = rand () % 4;
        if (positions[pos] != nullptr && positions[pos]->get_type() != WALL && positions[pos]->get_type() != GHOST) 
            ghosts[i] = positions[pos];
        ghosts[i]->set_type(GHOST);
    }
}


void Pacman::add_ghost (Block *ptr) {
    num_ghosts++;
    ghosts = (Block **) std::realloc(ghosts, sizeof(ghosts) + sizeof(Block *));
    if (ghosts == nullptr) exit (EXIT_FAILURE);
    ghosts[num_ghosts-1] = ptr;
}

bool Pacman::check_ghost_collision () {
    for (int i = 0; i < num_ghosts; i++) {
        if (pacman == ghosts[i]) return true;
    }
    return false;
}

void Pacman::run () {
    char in;
    for (;;) {
        display ();
        std::cin >> in;
        move_self (in);
        move_ghosts ();
        if (pacman == end) {
            std::cout << "YELL HEAH DUDE" << std::endl;
            break;
        }
        else if (check_ghost_collision()) {
            std::cout << "GAME OEVER" << std::endl;
            break;
        }
        else if (pacman == key) {
            std::cout << "GOT KEY" << std::endl;
        }
    }
}



Block::Block () {

}

void Block::set_type (BlockType t){
    type = t;
}

BlockType Block::get_type (){
    return type;
}

Field::Field (int m, int n){
    field = new Block[m*n];
    width = m;
    height = n;
}

Block *Field::get_block (int x, int y){
    if (x >= 0 && x < width && y >= 0 && y < height) 
        return &field[y*width + x];
    return nullptr; 
} 
