#ifndef __ADDYEAR_HPP__
#define __ADDYEAR_HPP__

#include "decorator.hpp"

using namespace std;

class addYear : public decorator{
        public:
                addYear(MovieInfo* newMovie): decorator(newMovie){}
                string output_Info(){
                        return "YEAR:" + m_newMovie->getYear()+"\n";
                }
                string getName(){return;}
                string getGenre(){ return; }
        int getRating(){ return; }
        int getRunTime(){ return; }
        int getYear(){ return; }
                void movieVisit(Visitor* visit){}

};

#endif

q
q
q
q
q
q
q
q
q
q
q
q

