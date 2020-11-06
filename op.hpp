#ifndef __OP_HPP__
#define __OP_HPP__

#include <string>
#include "base.hpp"

using namespace std;

class Op : public Base {
    public:
	Op(){};
        Op(double value){ 
	    this->num = value;
	};

        double evaluate() { 
	    return num; 
        }

        string stringify() { 
	    return to_string(num); 
	}
	
    private:
	double num = 0;
};

#endif //__OP_HPP__
