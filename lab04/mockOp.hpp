#ifndef MOCKOP_HPP
#define MOCKOP_HPP

#include "base.hpp"
#include <string>

using namespace std;

class MockOp: public Base {
    public:
        MockOp(double num) { 
            this->num = num;
        };

        virtual double evaluate() { return num; }
        virtual string stringify() { return to_string(num); }
    private:
        double num;

};

#endif
