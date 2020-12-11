#ifndef __ADDGENRE_HPP__
#define __ADDGENRE_HPP__

#include "decorator.hpp"
#include "movieInfo.hpp"

using namespace std;

class addGenre : public decorator{
	public:
		addGenre(MovieInfo* newMovie): decorator(newMovie){}
		string output_Info(){
			return m_newMovie->output_info() + "GENRE:" + m_newMovie->getGenre() + "\n";
		}
		string getName(){return "";}
		string getGenre(){ return ""; }
        int getRating(){ return 0; }
        int getRunTime(){ return 0; }
        int getYear(){ return 0; }
		void accept(Visitor* visi){}

};

#endif
