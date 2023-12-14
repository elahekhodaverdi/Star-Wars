#include "spaceship.hpp"
using namespace std;

Spaceship::Spaceship(rectangle_s _loc, int _vx, int _vy)
{
  location = _loc;
  vx = _vx;
  vy = _vy;
  state = ALIVE;
}
void Spaceship::erase_bullet(int index)
{
  bullets.erase(bullets.begin() + index);
}
void Spaceship::draw_bullets(Window *win, string filename)
{
  for (int i = 0; i < bullets.size(); i++)
  {
    bullets[i].draw_object(win, filename);
  }
}
int Spaceship::get_bullet_number()
{
  return bullets.size();
}
void Spaceship::set_state(State _state)
{
  state = _state;
}
void Spaceship::handle_being_on_screen_bullets(Window *win)
{
  for (int i = 0; i < bullets.size(); i++)
  {
    if (!bullets[i].is_on_screen(win))
    {
      bullets[i] = bullets[bullets.size() - 1];
      bullets.pop_back();
    }
  }
}
int Spaceship::is_shot(vector<Bullet> *bullets)
{
  if (state == DEAD)
    return NOT_SHOT;
  for (int i = 0; i < bullets->size(); i++)
  {
    if (is_hit((*bullets)[i]))
      return i;
  }
  return NOT_SHOT;
}
void Spaceship::bullet_move()
{
  for (int i = 0; i < bullets.size(); i++)
  {
    bullets[i].move();
  }
}
vector<Bullet> *Spaceship::get_bullets()
{
  return &bullets;
}

State Spaceship::get_state()
{
  return state;
}