#ifndef SUB_HPP
#define SUB_HPP

#include "base.hpp"
#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Sub: public Base {
    public:
        Sub() { };
        Sub(Base* base1, Base* base2) {
            left = base1;
            right = base2;
        };

        double evaluate() {
            double leftVariable = left->evaluate();
            double rightVariable = right->evaluate();

            return leftVariable - rightVariable;
        }
        string stringify() {
            return left->stringify() + " - " + right->stringify();
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
	
	void accept(CountVisitor* visitor){
	    visitor->visit_sub();
	}

    private:
        Base* left = nullptr;
        Base* right = nullptr;
};

#endif

