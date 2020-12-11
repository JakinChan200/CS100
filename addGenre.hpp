#ifndef __ADDGENRE_HPP__
#define __ADDGENRE_HPP__

#include "decorator.hpp"

using namespace std;

class addGenre : public decorator{
	public:
		addGenre(MovieInfo* newMovie): decorator(newMovie){}
		string output_Info(){
			return "GENRE:" + m_newMovie->getGenre()+"\n";
		}
		string getName(){return;}
		string getGenre(){ return; }
        int getRating(){ return; }
        int getRunTime(){ return; }
        int getYear(){ return; }
		void movieVisit(Visitor* visit){}

};

#endif
