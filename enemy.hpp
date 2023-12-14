#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "spaceship.hpp"
#include "defines.hpp"
class Enemy : public Spaceship
{
public:
    Enemy(rectangle_s _loc, Model _model);
    void draw_enemy(Window *win);
    void update_enemy();
    void handle_being_on_screen_enemy(Window *win);
    Model get_model();

private:
    Model model;
};
#endif