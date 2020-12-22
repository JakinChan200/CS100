#include <iostream>
#include <string>
#include "base.hpp"
using namespace std;

class Rand: public Base{
    private:
    	double a;
    public:
    	Rand(){
            a = rand() % 100;
        };

    	double evaluate(){
            return a;
    	}
    	
	string stringify(){   
            return to_string(a);
        }
};
