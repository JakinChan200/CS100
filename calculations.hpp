#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

#include "movieInfo.hpp"
#include "movie.hpp"
#include "newMovie.hpp"
#include "decorator.hpp"
#include "movieCategory.hpp"
#include "addGenre.hpp"
#include "addYear.hpp"
#include "addRuntime.hpp"
#include "addRating.hpp"
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

            //We can have 2 categories if you want, where 1 category is old movies, and another is new movies
            //The only thing you would have to change is make sure the below code runs twice, one for each category

            Visitor* vis = new Visitor();
            category->movieVisit(vis);
            vector<MovieInfo*> movieList = vis->getMovieVector();

            for(int i = 0; i < movieList.size(); i++){
                movieInfo* temp1  =  movieList[i];
		movieInfo* temp2  =  new addGenre(temp1);
		movieInfo* temp3  =  new addRating(temp2);
		movieInfo* temp4  =  new addYear(temp3);
		movieInfo* temp5  =  new addRuntime(temp4);
		cout << temp5->output_info() << endl;


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
