#ifndef MOVIECATEGORY_HPP
#define MOVIECATEGORY_HPP
#include "movieInfo.hpp"
#include <string>
#include <vector>

using namespace std;

class MovieCategory : public MovieInfo {
    public:
        MovieCategory(){};
        MovieCategory(string name){
            this->name = name;
        };
        string getName(){ return name; }
        string output_Info(){
            string final = "Category: " + name + "\n";
            for(auto element: movies){
                final += element->output_Info() + "\n";
            }
            return final;
        }
        void addMovie(MovieInfo* movie) {
            movies.push_back(movie);
        }
    private:
        string name = "";
        vector<MovieInfo*> movies;
};
#endif