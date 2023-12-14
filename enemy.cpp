#include "enemy.hpp"
Enemy::Enemy(rectangle_s _loc, Model _model)
{
  location = _loc;
  model = _model;
  state = ALIVE;
  if (_model = STATIC)
  {

    vx = 0;
    vy = 0;
  }
  else
  {
    vx = ENEMY_SPEED;
    vy = 0;
  }
}
void Enemy::handle_being_on_screen_enemy(Window *win)
{
  if (location.x < 0)
  {
    set_x(0);
    vx = -vx;
  }
  if (location.x + location.w > win->get_width())
  {
    set_x(win->get_width() - location.w);
    vx = -vx;
  }
  handle_being_on_screen_bullets(win);
}

Model Enemy::get_model()
{
  return model;
}
void Enemy::draw_enemy(Window *win)
{
  draw_bullets(win,ENEMY_BULLEET_FILENAME);
  if (state != DEAD)
    if (model == MOVING)
    {
      draw_object(win, MOVING_ENEMY_FILENAME);
    }
    else
      draw_object(win, STATIC_ENEMY_FILENAME);
}
void Enemy::update_enemy()
{
  if (state != DEAD)
    bullets.push_back(Bullet({location.x + location.w / 2 - BULLET_HEIGTH / 2, location.y + BULLET_HEIGTH / 2, BULLET_HEIGTH, BULLET_HEIGTH}, ENEMY_BULLET_SPEED));
}
