#ifndef RAND_HPP
#define RAND_HPP

#include <iostream>
#include <string>
#include "base.hpp"
#include "iterator.hpp"

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

};

#endif
