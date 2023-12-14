#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP
#include "object.hpp"
#include "bullet.hpp"
#include <vector>
class Spaceship : public Object
{
public:
  Spaceship(rectangle_s _loc, int _vx, int _vy);
  Spaceship() = default;
  void draw_bullets(Window *win,std::string filename);
  State get_state();
  int get_bullet_number();
  void bullet_move();
  void set_state(State _state);
  int is_shot(std::vector<Bullet> *bullets);
  void handle_being_on_screen_bullets(Window* win);
  void erase_bullet(int index);
  std::vector<Bullet> *get_bullets();

protected:
  State state;
  std::vector<Bullet> bullets;
};
#endif