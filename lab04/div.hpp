#include <iostream>
#include <string>
#include <cstdlib>
#include "base.hpp"
#include "op.hpp"

using namespace std;

class Div: public Base{
    private:
	Base* a = new Op(0);
	Base* b = new Op(1);
    public:
    	Div(){};
        Div(Base* left, Base* right){
	    delete a;
	    delete b;
            a = left;
            b = right;
    	};
    	
	double evaluate(){
            return (a->evaluate())/(b->evaluate());
        }
    	
	string stringify(){
            return ( "(" + a->stringify() + ") / (" + b->stringify() + ")" );
        }
};
