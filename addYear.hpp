#ifndef __ADDYEAR_HPP__
#define __ADDYEAR_HPP__

#include "decorator.hpp"
#include <iostream>
#include <string>

using namespace std;

class addYear : public decorator{
        public:
                addYear(MovieInfo* newMovie): decorator(newMovie){}
                string output_Info(){
                        return m_newMovie->output_Info() + "YEAR :" + to_string(m_newMovie->getYear()) + "\n";
                }
                string getName(){return "";}
                string getGenre(){ return ""; }
                int getRating(){ return 0; }
                int getRunTime(){ return 0; }
                int getYear(){ return 0; }
                void accept(Visitor* visit){}

};

#endif