#include "../header/rectangle.hpp"
#include "rectangle.cpp"
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[]){
	Rectangle *box1 = new Rectangle(2, 3);
	cout << "Area: " << box1->area() << endl;
	cout << "Perimeter: " << box1->perimeter() << endl; 
}
