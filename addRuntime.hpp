#ifndef __ADDRUNTIME_HPP__
#define __ADDRUNTIME_HPP__

#include "decorator.hpp"

using namespace std;

class addRuntime : public decorator{
        public:
                addRuntime(MovieInfo* newMovie): decorator(newMovie){}
                string output_Info(){
                        return "RUNTIME:" + m_newMovie->getRunTime()+"\n";
                }
                string getName(){return;}
                string getGenre(){ return; }
        int getRating(){ return; }
        int getRunTime(){ return; }
        int getYear(){ return; }
                void movieVisit(Visitor* visit){}

};

#endif
fndef __ADDRUNTIME_HPP__
#define __ADDRUNTIME_HPP__

#include "decorator.hpp"

using namespace std;

class addRuntime : public decorator{
        public:
                addRuntime(MovieInfo* newMovie): decorator(newMovie){}
                string output_Info(){
                        return "RUNTIME:" + m_newMovie->getRunTime()+"\n";
                }
                string getName(){return;}
                string getGenre(){ return; }
        int getRating(){ return; }
        int getRunTime(){ return; }
        int getYear(){ return; }
                void movieVisit(Visitor* visit){}

};

#endif

