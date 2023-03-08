#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

typedef enum {
    WALL,
    PACMAN,
    KEY,
    GHOST,
    GROUND,
    END,
} BlockType;

const char sprites[] = {'X', 'S', 'K', 'G', '.', 'T'};

class Block {
    private:
    BlockType type;

    public:
    int x, y;
    Block ();
    void set_type (BlockType t);
    BlockType get_type ();
};

class Field {
    private:
    Block * field;
    
    public:
    int width, height;
    Field (int m, int n);
    Block *get_block (int x, int y); 
    void set_block (int x, int y); 
};

class Pacman {
    public:
    Block *pacman;
    Block **ghosts;
    int num_ghosts;
    Block *key;
    Block *end;

    Pacman (char *filename);
    ~Pacman ();
    void display ();
    void run ();

    private:
    void add_ghost (Block *ptr);
    Field *new_field;
    bool check_ghost_collision ();
    void move_self (char in);
    void move_ghosts ();
};