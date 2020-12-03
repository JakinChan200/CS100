#ifndef __OP_HPP__
#define __OP_HPP__

#include <string>
#include "base.hpp"
#include "iterator.hpp"

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
	
	Iterator* create_iterator(){
            Iterator* temp = new NullIterator(this);
            return temp;
        }

        Base* get_left(){
            return nullptr;
        }

        Base* get_right(){
            return nullptr;
        }
	
    private:
	double num = 0;
};

#endif //__OP_HPP__
