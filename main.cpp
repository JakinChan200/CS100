#include "movieInfo.hpp"
#include "newMovie.hpp"
#include "decorator.hpp"
#include "addActors.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
        movieInfo* test_movie = new newMovie();
        cout << "Testing outputs with the decorator pattern. " << endl;
        cout << test_movie->output_info() << endl;

	movieInfo* decorated_movie = new addActors(test_movie);
	cout << "Testing movie decorated with addActors. " << endl;
	cout << decorated_movie->output_info() << endl;


}

