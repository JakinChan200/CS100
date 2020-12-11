#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

#include "Visitor.hpp"
#include "movieInfo.hpp"
#include "movie.hpp"
#include "movieCategory.hpp"
#include "decorator.hpp"
#include "addGenre.hpp"
#include "addRating.hpp"
#include <string>
#include <vector>

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

        string Calculate(){
            string final = "";
            MovieCategory* category = new MovieCategory("Preferred Movies");

            //find movies you want
            //If you find one you want, then run

            MovieInfo* temp1 = new Movie("fbdsakf", "fnsdf", 23, 420, 69);
            //following this format of course: Movie(string name, string genre, int rating, int runtime, int year){ 
            //Then add it to the category
            category->addMovie(temp1);

            //We can have 2 categories if you want, where 1 category is old movies, and another is new movies
            //The only thing you would have to change is make sure the below code runs twice, one for each category

            Visitor* friendly = new Visitor();
            category->accept(friendly);
            int numMovies = friendly->getCounter();

            vector<MovieInfo*> movies = category->getMovies();

            for(int i = 0; i < movies.size(); i++){
                final += movies[i]->output_Info();
                MovieInfo* temp = new addGenre(movies[i]);
                final += temp->output_Info();
            }

            return final;
        }
};
#endif