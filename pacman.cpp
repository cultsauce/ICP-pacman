#include "pacman.hpp"


Pacman::Pacman (char *filename) {
    std::ifstream file (filename);
    std::string line;
    int i = 0;
    getline(file, line);
    while (isdigit(line[i++]));
    m = atoi(line.substr(0, i).c_str());
    n = atoi(line.substr(i, std::string::npos).c_str());

    field = new std::string [m];
    i = 0;
    while (getline(file, line)) {
        int j = line.find('S');    
        if (j != std::string::npos) {
            pos[1] = i; 
            pos[0] = j;
        }
        j = line.find('K');    
        if (j != std::string::npos) {
            key[1] = i; 
            key[0] = j;
        }
        j = line.find('T');    
        if (j != std::string::npos) {
            end[1] = i; 
            end[0] = j;
        }
        j = line.find('G');    
        if (j != std::string::npos) {
            line.replace(j, 1, ".");
        }
        field[i++] = line;
    }
}

Pacman::~Pacman() {
}

void Pacman::display () {
    for (int i = 0; i < m; i++) {
        std::cout << field[i] << std::endl;
    }
}

void Pacman::move (char in) {
    field[pos[1]].replace(pos[0], 1, ".");
    switch (in) {
        case 'w':
            if (pos[1] > 0 && field[pos[1] - 1][pos[0]] != 'X') {
                pos[1] -= 1;
            }
            break;
        case 'a':
            if (pos[0] > 0 && field[pos[1]][pos[0] - 1] != 'X') {
                pos[0] -= 1;
            }
            break;
        case 's':
            if (pos[0] < n-1 && field[pos[1]][pos[0] + 1] != 'X') {
                pos[0] += 1;
            }
            break;
        case 'z':
            if (pos[1] < m-1 && field[pos[1] + 1][pos[0]] != 'X') {
                pos[1] += 1;
            }
            break;
    }
    field[pos[1]].replace(pos[0], 1, "S");
}

void Pacman::run () {
    char in;
    for (;;) {
        display ();
        std::cin >> in;
        move (in);
        if (pos[1] == end[1] && pos[0] == end[0]) {
            std::cout << "YELL HEAH DUDE" << std::endl;
            break;
        }
    }
}