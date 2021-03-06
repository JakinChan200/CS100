#ifndef MOVIE_HPP
#define MOVIE_HPP
#include "movieInfo.hpp"
#include "movieCategory.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Visitor;
class Movie : public MovieInfo {
    private:
        string name = "";
        string genre = "";
        int rating = 0;
        int runtime = 0;
        int year = 0;
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

        void accept(Visitor* visi){
            visi->visit();
        }
};
#endif