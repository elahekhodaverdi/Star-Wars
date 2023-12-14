#include "object.hpp"
using namespace std;

void Object::set_x(int _x)
{
    location.x = _x;
}
void Object::set_y(int _y)
{
    location.y = _y;
}

bool Object::is_hit(const Object &object)
{
    if ((abs(location.x + location.w / 2 - (object.location.w / 2 + object.location.x)) <= (object.location.w / 2 + location.w / 2)) &&
        (abs(location.y + location.h / 2 - (object.location.h / 2 + object.location.y)) <= (object.location.h / 2 + location.h / 2)))
    {
        return true;
    }
    return false;
}

Object::Object(rectangle_s _loc, int _vx, int _vy)
{
    location = _loc;
    vx = _vx;
    vy = _vy;
};
void Object::draw_object(Window *win, string filename)
{
    win->draw_img(filename, Rectangle(location.x, location.y, location.w, location.h));
}
void Object::move()
{
    location.x += vx;
    location.y += vy;
}
