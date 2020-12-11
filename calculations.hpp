#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP
#include "movieInfo.hpp"
#include "movie.hpp"
#include "newMovie.hpp"
//#include "decorator.hpp"
#include "movieCategory.hpp"
//#include "addGenre.hpp"
//#include "addRating.hpp"
//#include "addYear.hpp"
//#include "addRuntime.hpp"
//#include "addRating.hpp"
#include "Visitor.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Calculation {
    private:
        string movieGenre = "";
        int movieRating;
        int maxRunTime;
        int minYear;
        string fileName = ""; //in this case would be movieData.txt
    public:
        Calculation(){};
        Calculation(string prefGenre, int minRating, int maxRunTime, int minYear){
            this->movieGenre = prefGenre;
            this->movieRating = movieRating;
            this->maxRunTime = maxRunTime;
            this->minYear = minYear;
        };
	string Calculate(string fileName){
       	    string final = "";
            MovieCategory* category = new MovieCategory("Preferred Movies");

            ifstream movieData;
            movieData.open(fileName);
            string line;
            string temp;
            vector<string> currMovie;
            for (unsigned i = 0; i < 100; ++i) {
                int matches = 0;
                currMovie.clear();
                getline(movieData, line);
                stringstream ss(line);
                while (getline(ss, temp, ',')) {
                    currMovie.push_back(temp);
                }
                if(currMovie[1] == movieGenre){
                    matches++;
                }
                if(stoi(currMovie[2]) >= movieRating){
                    matches++;
                }
                if(stoi(currMovie[3]) <= maxRunTime){
                    matches++;
                }
                if(stoi(currMovie[4]) >= minYear){
                    matches++;
                }

                if(matches >= 2){
                    MovieInfo* temp1 = new Movie(currMovie[0], currMovie[1], currMovie[2], currMovie[3], currMovie[4]);
                    category->addMovie(temp1);
                }

            } 
            movieData.close();

            Visitor* friendly = new Visitor();
            category->accept(friendly);
            int numMovies = friendly->getCounter();

            vector<MovieInfo> movies = category->getMovies();
            for(int i = 0; i < movies.size(); i++){
                final += movies[i]->output_Info();
                MovieInfo temp = new addGenre(movies[i]);
                final += temp->output_Info();
            }

            return final;
       }
};
#endif

