#include <iostream>
#include <string>
#include <cstdlib>
#include "base.h"
using namespace std;

class Div: public Base{
    Base a,b;
    public:
    Div(){
        a = 0;
        b = 0;
    }
    Div(Base left, Base right){
        a = left;
        b = right;
    }
    virtual double evaluate(){
        return (a->evaluate())/(b->evaluate());
    }
    virtual string stringify(){
        return ( "(" + a->stringify() + "/" + b->stringify() + ")" );
    }
}