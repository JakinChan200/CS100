#ifndef VISITOR_TEST_HPP
#define VISITOR_TEST_HPP

#include "gtest/gtest.h"
#include "movieInfo.hpp"
#include "movie.hpp"
#include "movieCategory.hpp"
#include "Visitor.hpp"
#include <iostream>

using namespace std;

TEST(VisitorTest, basicFunctionTest) {
    MovieInfo* movie1 = new Movie("tempName");
    MovieCategory* cata1 = new MovieCategory("Testing");

    cata1->addMovie(movie1);
    Visitor* friendly = new Visitor();
    cata1->accept(friendly);
    EXPECT_EQ(friendly->getCounter(), 1);
    
}

TEST(VisitorTest, EmptyCategoryTest) {
    MovieCategory* cata1 = new MovieCategory("Testing");

    Visitor* friendly = new Visitor();
    cata1->accept(friendly);
    EXPECT_EQ(friendly->getCounter(), 0);
    
}

TEST(VisitorTest, MultipleMoviesTest) {
    MovieInfo* movie1 = new Movie("tempName");
    MovieInfo* movie2 = new Movie("tempName");
    MovieInfo* movie3 = new Movie("tempName");
    MovieInfo* movie4 = new Movie("tempName");
    MovieCategory* cata1 = new MovieCategory("Testing");

    cata1->addMovie(movie1);
    cata1->addMovie(movie2);
    cata1->addMovie(movie3);
    cata1->addMovie(movie4);
    Visitor* friendly = new Visitor();
    cata1->accept(friendly);
    EXPECT_EQ(friendly->getCounter(), 4);
}

TEST(VisitorTest, MultipleCategoriesTest) {
    MovieInfo* movie1 = new Movie("tempName");
    MovieInfo* movie2 = new Movie("tempName");
    MovieInfo* movie3 = new Movie("tempName");
    MovieInfo* movie4 = new Movie("tempName");
    MovieCategory* cata1 = new MovieCategory("Testing");
    MovieCategory* cata2 = new MovieCategory("Testing");

    cata1->addMovie(movie1);
    cata1->addMovie(movie2);
    cata2->addMovie(movie3);
    cata2->addMovie(movie4);
    Visitor* friendly = new Visitor();
    cata1->accept(friendly);
    EXPECT_EQ(friendly->getCounter(), 2);
}
#endif