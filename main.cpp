/*
#include "movieInfo.hpp"
#include "newMovie.hpp"
#include "decorator.hpp"
#include "addActors.hpp"
#include "addMovieTitle.hpp"
#include "addMovieDesc.hpp"
#include "addGenre.hpp"
*/
#include <iostream>
#include <string>
#include <fstream>

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
	cout << "First, please select the genre of movie that you're looking forby entering the corresponding number followed by enter:" << endl;
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
	cout << "18. Western" << endl << endl;
	int genreNum;
	cin >> genreNum;
	cout << endl;
	string genre = determine_genre(genreNum);

	cout << "Next, please enter the minimum rating percentage of the movies you're hoping to watch (scale: 1-100): ";
	int minimumRating;
	cin >> minimumRating;
	cout << endl;

	cout << "Next, please enter the maximum amount of length for the movies you're hoping to watch (in minutes): ";
	int maxLength;
	cin >> maxLength;
	cout << endl;
	
	cout << "Finally, please enter the minimum release year for the movies you're hoping to watch: ";
	int minimumYear;
	cin >> minimumYear;
	cout << endl;

	cout << genre << ", " << minimumRating << ", " << maxLength << ", " << minimumYear << endl;	

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
