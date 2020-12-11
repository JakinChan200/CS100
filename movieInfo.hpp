#ifndef MOVIEINFO_HPP
#define MOVIEINFO_HPP

#include <iostream>
#include <vector>

using namespace std;

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
        virtual void movieVisit(Visitor*) = 0;
    private:

};

#endif