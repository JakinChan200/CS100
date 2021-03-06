/*
#include "movieInfo.hpp"
#include "newMovie.hpp"
#include "decorator.hpp"
#include "addActors.hpp"
#include "addMovieTitle.hpp"
#include "addMovieDesc.hpp"
#include "addGenre.hpp"
*/
#include "movie.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
//#include "calculations.hpp"
#include <sstream>
#include <vector>

using namespace std;

string determine_genre(int genreNum);

int main(){
	// I have not yet received the info for movieInfo objects, so there are 
	// temporary commands in place for them in the meantime. ex: (movieInfo->title)
	/*
        movieInfo* test_movie = new newMovie();
        cout << "Testing outputs with the decorator pattern. " << endl;
        cout << test_movie->output_info() << endl;
	cout << "////////////////////////////////////////////////" << endl;

	movieInfo* decorated_movie = new addActors(test_movie);
	cout << "Testing movie decorated with addActors. " << endl;
	cout << decorated_movie->output_info() << endl;
        cout << "////////////////////////////////////////////////" << endl;
	

	movieInfo* movie2 = new addMovieTitle(decorated_movie);
	cout << "Decorating output with addTitle decorator" << endl;
	cout << movie2->output_info() << endl;
        cout << "////////////////////////////////////////////////" << endl;


	movieInfo* movie3 = new addMovieDesc(movie2);
        cout << "Decorating output with addMovieDesc decorator" << endl;
        cout << movie3->output_info() << endl;
        cout << "////////////////////////////////////////////////" << endl;
	

        movieInfo* movie4 = new addGenre(movie3);
        cout << "Decorating output with addGenre decorator" << endl;
        cout << movie4->output_info() << endl;
        cout << "////////////////////////////////////////////////" << endl;



	cout << "Testing complete." << endl;
	*/

	cout << endl << "Welcome to the Movie Recommendation Generator!" << endl << endl;
	cout << "In order to make the best recommendations possible, please answer the following questions..." << endl << endl;
	cout << "First, please select the genre of movie that you're looking for by entering the corresponding number followed by enter:" << endl;
	cout << "1. Action" << endl;
	cout << "2. Adventure" << endl;
	cout << "3. Animation" << endl;
	cout << "4. Comedy" << endl;
	cout << "5. Crime" << endl;
	cout << "6. Documentary" << endl;
	cout << "7. Drama" << endl;
	cout << "8. Family" << endl;
	cout << "9. Fantasy" << endl;
	cout << "10. History" << endl;
	cout << "11. Horror" << endl;
	cout << "12. Music" << endl;
	cout << "13. Mystery" << endl;
	cout << "14. Romance" << endl;
	cout << "15. Science Fiction" << endl;
	cout << "16. Thriller" << endl;
	cout << "17. War" << endl;
	cout << "18. Western" << endl;

	int genreNum = -1;
	cin >> genreNum;
	cout << endl;
	while(genreNum > 18 || genreNum < 1){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Sorry, that is not a valid number, please enter a valid number." << endl;
		cin >> genreNum;
	}
	cout << endl;
	string genre = determine_genre(genreNum);

	cout << "Next, please enter the minimum rating percentage of the movies you're hoping to watch (scale: 1-100): " << endl;
	cin.ignore(10000, '\n');
	int minimumRating = -1;
	cin >> minimumRating;
	while(minimumRating > 100 || minimumRating < 1){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Sorry, that is not a valid rating, please enter a valid rating." << endl;
		cin >> minimumRating;
	}
	cout << endl;

	cout << "Next, please enter the maximum amount of length for the movies you're hoping to watch (in minutes): " << endl;
	int maxLength = -1;
	cin >> maxLength;
	while(maxLength < 1){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Sorry, that is not a valid response, please enter a valid response" << endl;
		cin >> maxLength;
	}
	cout << endl;
	
	cout << "Finally, please enter the minimum release year for the movies you're hoping to watch: " << endl;
	int minimumYear = 2021;
	cin >> minimumYear;
	while(cin.fail() || minimumYear > 2020){
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Whoa, you must live in the future!" << endl;
		cout << "Please enter a valid year: " << endl;
		cin >> minimumYear;
	}
	cout << endl;

	// Movie preferredMovie = Movie("Preferred Movie", genre, minimumRating, maxLength, minimumYear);
		
	    ifstream movieData;
            movieData.open("movieData.txt");
            string line;
            string temp;
            vector<string> currMovie;
	    vector<string> recommendedMovies;
            for (unsigned i = 0; i < 100; ++i) {
                int matches = 0;
                currMovie.clear();
                getline(movieData, line);
                stringstream ss(line);
                while (getline(ss, temp, ',')) {
                    currMovie.push_back(temp);
                }
                if(currMovie[1] == genre){
                    matches++;
                }
                if(stoi(currMovie[2]) >= minimumRating){
                    matches++;
                }
                if(stoi(currMovie[3]) <= maxLength){
                    matches++;
                }
                if(stoi(currMovie[4]) >= minimumYear){
                    matches++;
                }

                if(matches >= 3){
                    recommendedMovies.push_back(currMovie[0]); 
                }

            } 
            movieData.close();
	
	if (recommendedMovies.size() == 0) {
		cout << "Sorry, none of our movies fit the standards you are hoping for." << endl << endl;
	}
	else {
		cout << "Based on the information you entered, here is a list of movies we recommend to watch." << endl << endl;
		for (unsigned i = 0; i < recommendedMovies.size(); ++i) {
			cout << i + 1 << ". " << recommendedMovies.at(i) << endl;
		}
	}

	
	return 0;

}

string determine_genre(int genreNum) {
	if (genreNum == 1) {return "Action";}
	else if (genreNum == 2) {return "Adventure";}
	else if (genreNum == 3) {return "Animation";}
	else if (genreNum == 4) {return "Comedy";}
	else if (genreNum == 5) {return "Crime";} 
	else if (genreNum == 6) {return "Documentary";}
	else if (genreNum == 7) {return "Drama";}
	else if (genreNum == 8) {return "Family";}
	else if (genreNum == 9) {return "Fantasy";}
	else if (genreNum == 10) {return "History";} 
	else if (genreNum == 11) {return "Horror";} 
	else if (genreNum == 12) {return "Music";}
	else if (genreNum == 13) {return "Mystery";} 
	else if (genreNum == 14) {return "Romance";}
	else if (genreNum == 15) {return "Science Fiction";}
	else if (genreNum == 16) {return "Thriller";}
	else if (genreNum == 17) {return "War";}
	else {return "Western";} 
}
