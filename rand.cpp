#include <iostream>
#include <string>
#include "base.h"
using namespace std;

class Rand: public Base{
    double a;
    public:
    Rand(){
        a = rand();
    }
    virtual double evaluate(){
        return a;
    }
    virtual string stringify(){   
        return to_string(a);
    }
}