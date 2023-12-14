#include "game.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  Window *win;

  Game star_wars(win);
  star_wars.run(argv[1]);
}
