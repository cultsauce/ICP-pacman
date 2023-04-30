#include "game.hpp"


int main(int argc, char *argv[]) {
  Game *game = new Game (argc, argv, "map.txt");
  return game->run();
}
