#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

#include "movieInfo.hpp"
#include "movie.hpp"
#include "movieCategory.hpp"
#include "addGenre.hpp"
#include "Visitor.hpp"
#include <string>

using namespace std;

class Calculation {
    public:
        Calculation(){};
        Calculation(string prefGenre, int minRating, int maxRunTime, int minYear){
            this->movieGenre = prefGenre;
            this->movieRating = movieRating;
            this->maxRunTime = maxRunTime;
            this->minYear = minYear;
        };

        string Calculate(){
            string final = "";
            MovieCategory* category = new MovieCategory("Preferred Movies");

            //find movies you want
            //If you find one you want, then run

            MovieInfo* temp = new Movie("fbdsakf", "fnsdf", 23, 420, 69);
            //following this format of course: Movie(string name, string genre, int rating, int runtime, int year){ 
            //Then add it to the category
            category->addMovie(temp);

            Visitor* vis = new Visitor();
            category->movieVisit(vis);
            vector<MovieInfo*> movieList = vis->getMovieVector();

            for(int i = 0; i < movieList.size(); i++){
                final += movieList[i]->getName();
                temp = new addGenre(movieList[i]);
                final += temp->output_Info();

                //now do the same with the other classes
            }

            return final;
        }
    private:
        string movieGenre = "";
        int movieRating;
        int maxRunTime;
        int minYear;
        string fileName = ""; //in this case would be movieData.txt
};

#endif