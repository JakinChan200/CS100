#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "movieInfo.hpp"
#include "visitor.hpp"
#include <string>
#include <vector>

using namespace std;

class Movie : public MovieInfo {
    public:
        Movie(){};
        Movie(string name){
            this->name = name;
        };
        Movie(string name, string genre, int rating, int runtime, int year){ 
            this->name = name;
            this->genre = genre;
            this->rating = rating;
            this->runtime = runtime;
            this->year = year;
        };
        string getName(){ return name; }
        string output_Info(){
            return name;
        }
        string getGenre(){ return genre; }
        int getRating(){ return rating; }
        int getRunTime(){ return runtime; }
        int getYear(){ return year; }
        void movieVisit(Visitor* visit){
            visit->addVisit(this);
        }
    
    private:
        string name = "";
        string genre = "";
        int rating = 0;
        int runtime = 0;
        int year = 0;
};
#endif