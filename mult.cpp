#include <iostream>
#include <string>
#include "base.h"
using namespace std;

class Mult: public Base{
    Base a,b;
    public:
    Mult(){
        a = 0;
        b = 0;
    }
    Mult(Base left, Base right){
        a = left;
        b = right;
    }
    virtual double evaluate(){
        return a->evaluate() * b->evaluate();
    }
    virtual string stringify(){
        return ( "(" + a->stringify() + "*" + b->stringify() + ")" );
    }
}