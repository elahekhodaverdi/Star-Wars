#ifndef HOSTAGES_HPP
#define HOSTAGES_HPP
#include "enemy.hpp"
#include "player.hpp"
class Hostages
{
public:
    void draw_hostages(Window *win);
    void hit_hostages(Player *player);
    void add_hostage(Spaceship _hostage);
    void clear_hostages();

private:
    std::vector<Spaceship> hostages;
};
#endif