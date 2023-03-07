#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Pacman {
    public:
    Pacman (char *filename);
    ~Pacman ();
    void display ();
    void run ();

    private:
    std::string *field;
    int pos[2] = {-1,-1}, key[2] = {-1,-1}, end[2] = {-1,-1};
    int m, n;
    void move (char in);
};