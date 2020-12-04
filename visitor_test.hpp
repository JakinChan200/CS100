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
#include "visitor.hpp"
#include <iostream>

TEST(visitorTest, AddTest) {
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(4);
    Base* variable3 = new Op(7);

    Base* operator1 = new Add(variable1, variable2);
    Base* dummyNode = new Add(operator1, variable3);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }
    EXPECT_EQ(op_count, 3);
    EXPECT_EQ(add_count, 1);
}

TEST(visitorTest, SubTest) {
    Base* variable1 = new Op(5);
    Base* variable2 = new Op(9);
    Base* variable3 = new Op(7);

    Base* operator1 = new Sub(variable1, variable2);
    Base* dummyNode = new Sub(operator1, variable3);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }
    EXPECT_EQ(op_count, 3);
    EXPECT_EQ(sub_count, 1);
}

TEST(visitorTest, MultTest) {
    Base* variable1 = new Op(3);
    Base* variable2 = new Op(2);
    Base* variable3 = new Op(4);

    Base* operator1 = new Mult(variable1, variable2);
    Base* dummyNode = new Mult(operator1, variable3);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }
    EXPECT_EQ(op_count, 3);
    EXPECT_EQ(mult_count, 1);
}

TEST(visitorTest, DivTest) {
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(6);
    Base* variable3 = new Op(7);

    Base* operator1 = new Div(variable1, variable2);
    Base* dummyNode = new Div(operator1, variable3);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }
    EXPECT_EQ(op_count, 3);
    EXPECT_EQ(div_count, 1);
}

TEST(visitorTest, PowTest) {
    Base* variable1 = new Op(5);
    Base* variable2 = new Op(1);
    Base* variable3 = new Op(8);

    Base* operator1 = new Pow(variable1, variable2);
    Base* dummyNode = new Pow(operator1, variable3);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }
    EXPECT_EQ(op_count, 3);
    EXPECT_EQ(pow_count, 1);
}

TEST(visitorTest, BasicFunctTest){
    Base* variable1 = new Op(0);
    Base* variable2 = new Op(2);
    Base* variable3 = new Op(4);
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
	
    EXPECT_EQ(visitor1->op_count(), 4);
    EXPECT_EQ(visitor1->add_count(), 1);
    EXPECT_EQ(visitor1->sub_count(), 1);
    
}

TEST(visitorTest, BasicFunctContTest){
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(3);
    Base* variable3 = new Op(5);
    Base* variable4 = new Op(1);

    Base* operator1 = new Mult(variable1, variable2);
    Base* operator2 = new Div(variable3, variable4);
    Base* dummyNode = new Add(operator1, operator2);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }
	
    EXPECT_EQ(visitor1->op_count(), 4);
    EXPECT_EQ(visitor1->div_count(), 1);
    EXPECT_EQ(visitor1->mult_count(), 1);
    
}

TEST(visitorTest, BasicFunctContTest){
    Base* variable1 = new Op(7);
    Base* variable2 = new Op(5);
    Base* variable3 = new Op(4);
    Base* variable4 = new Op(9);

    Base* operator1 = new Pow(variable1, variable2);
    Base* operator2 = new Rand();
    Base* dummyNode = new Pow(operator1, operator2);

    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();
    
    iter->first();
    for(iter->first(); iter->is_done() == false; iter->next()){
        iter->current()->accept(visitor1);
    }

    EXPECT_EQ(visitor1->op_count(), 4);
    EXPECT_EQ(visitor1->rand_count(), 1);
    EXPECT_EQ(visitor1->pow_count(), 1);
    
}


#endif
