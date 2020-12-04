#ifndef MULT_HPP
#define MULT_HPP

#include <iostream>
#include <string>
#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

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
	
	Iterator* create_iterator(){
            Iterator* temp = new BinaryIterator(this);
            return temp;
        }

        Base* get_left(){
            return a;
        }

        Base* get_right(){
            return b;
        }
	
	void accept(CountVisitor* visitor){
	    visitor->visit_mult();
	}
    private:
	Base* a = nullptr;
	Base* b = nullptr;
};

#endif
