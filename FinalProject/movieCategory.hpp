#ifndef MOVIECATEGORY_HPP
#define MOVIECATEGORY_HPP
#include "movieInfo.hpp"
#include "Visitor.hpp"
#include "decorator.hpp"
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
        void addMovie(MovieInfo* movie1) {
            movies.push_back(movie1);
        }

        void accept(Visitor* visi){
            for(int i = 0; i < movies.size(); i++){
                movies[i]->accept(visi);
            }
        }

        vector<MovieInfo*> getMovies(){
            return movies;
        }
        string getGenre(){ return ""; }
        int getRating(){ return 0; }
        int getRunTime(){ return 0; }
        int getYear(){ return 0; }
    private:
        string name = "";
        vector<MovieInfo*> movies;
};
#endif
