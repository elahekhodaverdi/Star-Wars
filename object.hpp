#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "rectangle_s.hpp"
#include "rsdl.hpp"
#include <math.h>
#include <string>
class Object
{
public:
    Object(rectangle_s _loc, int _vx, int _vy);
    Object() = default;
    void draw_object(Window *win, std::string filename);
    void move();
    bool is_on_screen(Window *win);
    bool is_hit(const Object &object);
    void set_x(int _x);
    void set_y(int _y);

protected:
    rectangle_s location;
    int vx;
    int vy;
};
#endif