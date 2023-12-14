#include "player.hpp"
Player::Player(rectangle_s _loc, int _vx, int _vy)
    : Spaceship(_loc, _vx, _vy)
{
}
void Player::shoot()
{
  bullets.push_back(Bullet({location.x + location.w / 2 - BULLET_HEIGTH / 2, location.y - BULLET_HEIGTH / 2, BULLET_HEIGTH, BULLET_HEIGTH}, -PLAYER_BULLET_SPEED));
}

void Player::handle_key_press(char key)
{
  switch (key)
  {
  case 'd':
    vx = PLAYER_SPEED;
    break;
  case 'a':
    vx = -PLAYER_SPEED;
    break;
  case 'w':
    vy = -PLAYER_SPEED;
    break;
  case 's':
    vy = PLAYER_SPEED;
    break;
  case ' ':
    shoot();
    break;
  }
}

void Player::handle_being_on_screen_player(Window *win)
{
  if (location.x < 0)
  {
    set_x(0);
    vx = 0;
  }
  if (location.x + location.w > win->get_width())
  {
    set_x(win->get_width() - location.w);
    vx = 0;
  }
  if (location.y < 0)
  {
    set_y(0);
    vy = 0;
  }
  if (location.y + location.h > win->get_height())
  {
    set_y(win->get_height() - location.h);
    vy = 0;
  }
  handle_being_on_screen_bullets(win);
}

void Player::handle_key_release(char key)
{
  switch (key)
  {
  case 'd':
    vx = 0;
    break;
  case 'a':
    vx = 0;
    break;
  case 'w':
    vy = 0;
    break;
  case 's':
    vy = 0;
    break;
  }
}