#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "movieInfo.hpp"
#include "movieCategory.hpp"
#include "movie.hpp"
#include <vector>

using namespace std;

class Visitor {
    public:
        Visitor(){};

        void addVisit(MovieInfo* tempMovie){
            movieVector.push_back(tempMovie);
        }

        vector<MovieInfo*> getMovieVector(){
            return movieVector;
        }

    private:
        vector<MovieInfo*> movieVector;
};

#endif