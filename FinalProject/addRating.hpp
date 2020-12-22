#ifndef __ADDRATING_HPP__
#define __ADDRATING_HPP__

#include "decorator.hpp"
#include "movieInfo.hpp"
#include <iostream>
#include <string>

using namespace std;

class addRating : public decorator{
        public:
                addRating(MovieInfo* newMovie): decorator(newMovie){}
                string output_Info(){
                        return m_newMovie->output_Info() + "RATING:" + to_string(m_newMovie->getRating()) + "\n";
                }
                string getName(){return "";}
                string getGenre(){ return ""; }
                int getRating(){ return 0; }
                int getRunTime(){ return 0; }
                int getYear(){ return 0; }
                void accept(Visitor* visit){}

};

#endif
