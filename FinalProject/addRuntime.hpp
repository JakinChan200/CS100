#ifndef __ADDRUNTIME_HPP__
#define __ADDRUNTIME_HPP__

#include "decorator.hpp"
#include <string>
#include <iostream>

using namespace std;

class addRuntime : public decorator{
        public:
                addRuntime(MovieInfo* newMovie): decorator(newMovie){}
                string output_Info(){
                        return m_newMovie->output_Info() + "RUNTIME: " + to_string(m_newMovie->getRunTime()) + "\n";
                }
                string getName(){return "";}
                string getGenre(){ return ""; }
                int getRating(){ return 0; }
                int getRunTime(){ return 0; }
                int getYear(){ return 0; }
                void accept(Visitor* visit){}

};

#endif

