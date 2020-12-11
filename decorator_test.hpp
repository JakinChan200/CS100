#ifndef DECORATOR_TEST_HPP
#define DECORATOR_TEST_HPP

#include "gtest/gtest.h"
#include "movieInfo.hpp"
#include "movie.hpp"
#include "decorator.hpp"
#include "addGenre.hpp"
#include "addRating.hpp"
#include "addYear.hpp"
#include "addRuntime.hpp"
#include "movieCategory.hpp"
#include <iostream>

using namespace std;

TEST(DecoratorTest, GenreTest) {
    MovieInfo* movie1 = new Movie("tempName", "Adventure", 12, 20, 2020);
    MovieInfo* genre = new addGenre(movie1);
    cout << genre->output_Info() << endl;
}

TEST(decoratorTest, RatingTest) {
    MovieInfo* movie1 = new Movie("tempName", "Adventure", 12, 20, 2020);
    MovieInfo* rating = new addRating(movie1);
    cout << rating->output_Info() << endl;
}

TEST(DecoratorTest, runtimeTest) {
    MovieInfo* movie1 = new Movie("tempName", "Adventure", 12, 20, 2020);
    MovieInfo* runtime = new addRuntime(movie1);
    cout << runtime->output_Info() << endl;
}

TEST(DecoratorTest, yearTest) {
    MovieInfo* movie1 = new Movie("tempName", "Adventure", 12, 20, 2020);
    MovieInfo* year = new addYear(movie1);
    cout << year->output_Info() << endl;
}
/*
TEST(DecoratorTest, StackDecoratorTest) {
    MovieInfo* movie1 = new Movie("tempName", "Adventure", 12, 20, 2020);
    MovieInfo* year = new addGenre(movie1);
    MovieInfo* movie2 = new addRating(year);
    MovieInfo* movie3 = new addRuntime(movie2);
    MovieInfo* movie4 = new addYear(movie3);
    cout << movie4->output_Info() << endl;
}*/

#endif