#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "movieInfo.hpp"
#include <string>

using namespace std;

class decorator : public MovieInfo {
	protected:
		MovieInfo* m_newMovie;
	public:
		decorator(MovieInfo* newMovie): m_newMovie(newMovie){}
		string output_info(){
			return m_newMovie->output_Info();
		}


};

#endif

