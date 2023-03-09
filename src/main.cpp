#include "game.hpp"

int main(int argc, char *argv[]) {
  std::string filename = "map.txt";
  Game *game = new Game (argc, argv);
  return game->run(filename);
}
