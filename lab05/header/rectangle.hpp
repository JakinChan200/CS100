#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle();
        Rectangle(int w,int h);

        void set_width(int w);
        void set_height(int h);
        int area();
        int perimeter();
	int getWidth();
	int getHeight();
};

#endif // RECTANGLE_HPP
