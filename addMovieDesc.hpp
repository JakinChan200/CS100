#ifndef __ADDMOVIEDESC_HPP__
#define __ADDMOVIEDESC_HPP__

using namespace std;

class addMovieDesc : public decorator {
	public:
		addMovieDesc(movieInfo *newMovie): decorator(newMovie){}
};



#endif
