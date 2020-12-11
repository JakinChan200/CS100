#ifndef __ADDRATING_HPP__
#define __ADDRATING_HPP__

#include "decorator.hpp"

using namespace std;

class addRating : public decorator{
	public:
		addRating(MovieInfo* newMovie): decorator(newMovie){}
		string output_Info(){
			return "RATING:" + m_newMovie->getRating()+"\n";
		}
		string getName(){return;}
		string getGenre(){ return; }
        int getRating(){ return; }
        int getRunTime(){ return; }
        int getYear(){ return; }
		void movieVisit(Visitor* visit){}

};

#endif
