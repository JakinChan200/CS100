#ifndef POW_HPP
#define POW_HPP

#include "base.hpp"
#include <string>
#include <tgmath.h>

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
            
     private:
        Base* left = nullptr;
        Base* right = nullptr;
};
#endif
