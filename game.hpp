#ifndef GAME_HPP
#define GAME_HPP
#include "rsdl.hpp"
#include "hostages.hpp"
#include "enemies.hpp"
#include "player.hpp"
#include <vector>
#include <fstream>
#include <string>
#include "defines.hpp"
#include "map.hpp"
#include <time.h>

class Game
{
public:
    Game(Window *_win);
    void fix_element_in_window(int current_map);
    void draw_board();
    void update_objects(int &duration);
    void get_maps(std::ifstream &input_csv, int round, int length, int width);
    void read_file(char *map_filename);
    void run(char *map_filename);
    void process_events();
    void move_objects();
    void handle_being_on_screen();
    void hit();
    void end_of_game(State state);
    void clean_map();

private:
    Player player;
    Hostages hostages;
    Enemies enemies;
    std::vector<map_s> maps;
    Window *win;
    bool game_running;
};
#endif