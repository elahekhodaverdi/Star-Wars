#include "bullet.hpp"
using namespace std;
Bullet::Bullet(rectangle_s _loc, int _vy)
{
    location = _loc;
    vx = 0;
    vy = _vy;
}
bool Bullet::is_on_screen(Window *win)
{
    if ((location.y + location.h <= 0) || (location.y >= win->get_height()))
        return false;
    return true;
}