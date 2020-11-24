#ifndef __ADDGENRE_HPP__
#define __ADDGENRE_HPP__

#include "decorator.hpp"

using namespace std;

class addGenre : public decorator{
	public:
		addGenre(movieInfo* newMovie): decorator(newMovie){}
		string output_info(){
			return m_newMovie->output_info() + "GENRE: (movieInfo->genre)\n";
		}

};

#endif
