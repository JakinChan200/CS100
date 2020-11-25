#ifndef MULT_HPP
#define MULT_HPP

#include <iostream>
#include <string>
#include "base.hpp"
using namespace std;

class Mult: public Base{
    public:
    	Mult(Base* left, Base* right){
            a = left;
            b = right;
    	}
    
	double evaluate(){
            return a->evaluate() * b->evaluate();
    	}

    	string stringify(){
            return ( "(" + a->stringify() + ") * (" + b->stringify() + ")" );
    	}
    private:
	Base* a = nullptr;
	Base* b = nullptr;
};

#endif
