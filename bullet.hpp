#ifndef BULLET_HPP
#define BULLET_HPP
#include "object.hpp"
#include "defines.hpp"
class Bullet : public Object
{
public:
    Bullet(rectangle_s _loc, int vx);
    bool is_on_screen(Window *win);
private:
};
#endif