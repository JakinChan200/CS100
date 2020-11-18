#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"
#include <string>

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

    private:
        Base* left = nullptr;
        Base* right = nullptr;
};

#endif
