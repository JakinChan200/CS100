#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"
#include <string>
#include "iterator.hpp"

using namespace std;

class Add: public Base {
    public:
        Add() { };
        Add(Base* num1, Base* num2) {
            left = num1;
            right = num2;
        };

        double evaluate() {
            return left->evaluate() + right->evaluate();
        }

        string stringify() {
            return left->stringify() + " + " + right->stringify() + " ";
        }

	Iterator* create_iterator(){
	    Iterator* temp = new BinaryIterator(this);
	    return temp;
	}
	
	Base* get_left(){
	    return left;
	}
	
	Base* get_right(){
	    return right;   
	}

    private:
        Base* left = nullptr;
        Base* right = nullptr;
};

#endif
