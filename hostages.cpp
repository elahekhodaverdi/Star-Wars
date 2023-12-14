#include "hostages.hpp"
void Hostages::add_hostage(Spaceship _hostage)
{
    hostages.push_back(_hostage);
}
void Hostages::draw_hostages(Window *win)
{
    for (int i = 0; i < hostages.size(); i++)
    {
        hostages[i].draw_object(win, HOSTAGE_FILENAME);
    }
}
void Hostages::clear_hostages()
{
    hostages.clear();
}

void Hostages::hit_hostages(Player *player)
{
    int bullet_index;
    for (int i = 0; i < hostages.size(); i++)
    {
        if (player->is_hit(hostages[i])&& player->get_state()!= DEAD)
        {
            hostages[i].set_state(DEAD);
            player->set_state(DEAD);
        }
    }
    for (int i = 0; i < hostages.size(); i++)
    {
        if ((bullet_index = hostages[i].is_shot(player->get_bullets())) != NOT_SHOT)
        {
            hostages[i].set_state(DEAD);
            player->set_state(DEAD);
            player->erase_bullet(bullet_index);
        }
    }
}
