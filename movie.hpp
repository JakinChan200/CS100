#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "movieInfo.hpp"
#include <string>
#include <vector>

using namespace std;

class Movie : public MovieInfo {
    public:
        Movie(){};
        Movie(string name){ 
            this->name = name;
        };
        string getName(){ return name; }
        string output_Info(){
            return name;
        }

    private:
        string name = "";
};
#endif