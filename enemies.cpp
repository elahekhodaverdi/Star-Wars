#include "enemies.hpp"
void Enemies::draw_enemies(Window *win)
{
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].draw_enemy(win);
    }
}
void Enemies::erase_dead_enemies()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].get_state() == DEAD && enemies[i].get_bullet_number() == 0)
            enemies.erase(enemies.begin() + i);
    }
}
void Enemies::shoot_enemies(int &duration)
{
    if (duration == ENEMY_SHOOT_DURATION)
    {
        for (int i = 0; i < enemies.size(); i++)
            enemies[i].update_enemy();
        duration = 0;
    }
}
void Enemies::hit_enemies(Player *player)
{
    int bullet_index;
    for (int i = 0; i < enemies.size(); i++)
    {
        if ((bullet_index = enemies[i].is_shot(player->get_bullets())) != NOT_SHOT)
        {
            enemies[i].set_state(DEAD);
            player->erase_bullet(bullet_index);
        }
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        if ((bullet_index = player->is_shot(enemies[i].get_bullets())) != NOT_SHOT)
        {
            enemies[i].erase_bullet(bullet_index);
            player->set_state(DEAD);
        }
    }
    for (int i = 0; i < enemies.size(); i++)
    {

        if (player->is_hit(enemies[i])&& player->get_state()!= DEAD)
        {
            player->set_state(DEAD);
            enemies[i].set_state(DEAD);
        }
    }
}
void Enemies::move_enemies()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].get_model() == MOVING && enemies[i].get_state() != DEAD)
            enemies[i].move();
        enemies[i].bullet_move();
    }
}

void Enemies::clear_enemies()
{
    enemies.clear();
}

void Enemies::handle_being_on_screen_enemies(Window *win)
{
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].handle_being_on_screen_enemy(win);
    }
}
void Enemies::add_enemy(Enemy _enemy)
{
    enemies.push_back(_enemy);
}

int Enemies::get_number_of_enemies()
{
    int counter = 0;
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].get_state() != DEAD)
            counter += 1;
    }

    return counter;
}
