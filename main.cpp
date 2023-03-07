#include "pacman.hpp"

int main (int argc, char *argv[]) {
    char filename[] = "input.txt";
    Pacman pacman = Pacman (filename);
    pacman.run ();
}