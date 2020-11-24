#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "movieInfo.hpp"
#include <string>

using namespace std;

class decorator : public movieInfo {
	protected:
		movieInfo* m_newMovie;
	public:
		decorator(movieInfo* newMovie): m_newMovie(newMovie){}
		string output_info(){
			return m_newMovie->output_info();
		}


};

#endif

