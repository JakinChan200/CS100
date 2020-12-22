#include "../header/rectangle.hpp"

using namespace std;

Rectangle::Rectangle() {
    set_width(0);
    set_height(0);
}

Rectangle::Rectangle(int w,int h) {
    set_width(w);
    set_height(h);
}

void Rectangle::set_width(int w) {
    this->width = w;
}

void Rectangle::set_height(int h) {
    this->height = h;
}

int Rectangle::area() {
    return width * height;
}

int Rectangle::perimeter() {
    return 2*(width + height);
}

int Rectangle::getWidth(){
    return width;
}

int Rectangle::getHeight(){
    return height;
}
