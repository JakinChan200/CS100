#ifndef VISITOR_TEST_HPP
#define VISITOR_TEST_HPP

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "iterator.hpp"
#include <iostream>

TEST(visitorTest, BasicFunctTest){
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(3);
    Base* variable3 = new Op(5);
    Base* variable4 = new Op(1);

    Base* operator1 = new Add(variable1, variable2);
    Base* operator2 = new Sub(variable3, variable4);
    Base* dummyNode = new Add(operator1, operator2);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }
    /*while(iter->is_done() == false){
	iter->current()->accept(visitor1);
	iter->next();
    }*/
	
    EXPECT_EQ(visitor1->op_count(), 4);
    EXPECT_EQ(visitor1->add_count(), 1);
    EXPECT_EQ(visitor1->sub_count(), 1);
    
}


#endif
