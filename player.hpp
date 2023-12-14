#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "spaceship.hpp"
#include "defines.hpp"
class Player : public Spaceship
{
public:
    Player(rectangle_s _loc, int _vx, int _vy);
    Player(){};
    void handle_key_press(char key);
    void handle_key_release(char key);
    void handle_being_on_screen_player(Window *win);
    void shoot();

private:
};

#endif