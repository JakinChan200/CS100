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
    Visitor* friendly;
    cata1->accept(friendly);
    EXPECT_EQ(friendly->getCounter(), 1);
    
}
#endif