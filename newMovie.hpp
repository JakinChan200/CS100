#ifndef __NEWMOVIE_HPP__
#define __NEWMOVIE_HPP__

#include "movieInfo.hpp"


using namespace std;

class newMovie : public movieInfo {
	public:
		string output_info(){
			return "Base Movie\n";
		}
		
};





#endif

