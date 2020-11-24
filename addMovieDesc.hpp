#ifndef __ADDMOVIEDESC_HPP__
#define __ADDMOVIEDESC_HPP__
#include "decorator.hpp"


using namespace std;

class addMovieDesc : public decorator {
	public:
		addMovieDesc(movieInfo *newMovie): decorator(newMovie){}
		string output_info(){
			return m_newMovie->output_info() + "Description of the Movie: (movieInfo->movieDesc)\n";
			}

};



#endif
