#ifndef __ADDMOVIETITLE_HPP__
#define __ADDMOVIETITLE_HPP__

#include "decorator.hpp"

using namespace std;

class addMovieTitle : public decorator{
	public:
		addMovieTitle(movieInfo* newMovie): decorator(newMovie){}
		string output_info(){
			return m_newMovie->output_info() + "Title of recommended movie: (movieInfo->title)\n";
		}
};


#endif

