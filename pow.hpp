#ifndef POW_HPP
#define POW_HPP

#include "base.hpp"
#include <string>
#include <tgmath.h>
#include "iterator.hpp"

using namespace std;

class Pow: public Base {
    public:
        Pow() { };
        Pow(Base* base1, Base* base2) {
            left = base1;
            right = base2;
        };

        double evaluate() {
            double baseResult = left->evaluate();
            double power = right->evaluate();

            return pow(baseResult, power);
        }
        string stringify() {
            return "(" + left->stringify() + ") ** (" + right->stringify() + ") ";
        }
        
	Iterator* create_iterator(){
            Iterator* temp = new BinaryIterator(this);
            return temp;
        }

        Base* get_left(){
            return left;
        }

        Base* get_right(){
            return right;
        }
    
     private:
        Base* left = nullptr;
        Base* right = nullptr;
};
#endif
