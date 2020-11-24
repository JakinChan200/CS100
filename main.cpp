
#include "movieInfo.hpp"
#include "newMovie.hpp"
#include "decorator.hpp"
#include "addActors.hpp"
#include "addMovieTitle.hpp"
#include "addMovieDesc.hpp"
#include "addGenre.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){
	// I have not yet received the info for movieInfo objects, so there are 
	// temporary commands in place for them in the meantime. ex: (movieInfo->title)
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


}

