#ifndef MOVIEINFO_HPP
#define MOVIEINFO_HPP

//#include "calculations.hpp"
#include "Visitor.hpp"
#include "movieInfo.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//class Calculation;
class MovieInfo {
    public:
        MovieInfo(){};
        virtual string output_Info() = 0;
        //virtual void add() = 0;
        virtual string getName() = 0;
        virtual string getGenre() = 0;
        virtual int getRating() = 0;
        virtual int getRunTime() = 0;
        virtual int getYear() = 0;
        virtual void accept(Visitor* visi) = 0;
};

#endif