#ifndef __ADDACTORS_HPP__
#define __ADDACTORS_HPP__

#include <iostream>
#include "decorator.hpp"


using namespace std;


class addActors : public decorator{
	public:
		addActors(movieInfo *newMovie): decorator(newMovie){}
		string output_info(){
			return  m_newMovie->output_info() + "ACTORS/ACTRESSES: (movieInfo->actorName)\n";
		}
};


#endif

