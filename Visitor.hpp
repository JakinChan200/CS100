#ifndef VISITOR_HPP
#define VISITOR_HPP
#include <iostream>
using namespace std;


class Visitor {
    private:
        int num = 0;
    public:
        Visitor(){ 
            num = 0;
        };
        void visit(){
            num++;
        }

        int getCounter(){
            return num;
        }
};

#endif