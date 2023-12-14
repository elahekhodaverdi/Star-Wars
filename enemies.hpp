#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include "enemy.hpp"
#include "player.hpp"
class Enemies
{
public:
    void draw_enemies(Window *win);
    void add_enemy(Enemy _enemy);
    void erase_dead_enemies();
    void shoot_enemies(int &duration);
    void hit_enemies(Player *player);
    void handle_being_on_screen_enemies(Window *win);
    int get_number_of_enemies();
    void clear_enemies();
    void move_enemies();

private:
    std::vector<Enemy> enemies;
};
#endif