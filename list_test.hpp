#ifndef __LIST_TEST_HPP__
#define __LIST_TEST_HPP__

#include "gtest/gtest.h"
#include "container.hpp"
#include "list.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "base.hpp"
#include <iostream>

TEST(ListTest, ListEmptyConstructor) {
    Container* test = new ListContainer();
    EXPECT_EQ(test->sort(), -1);
}

TEST(ListTest, ListRegInput) {
    Base* variable1 = new Op(0);
    Base* variable2 = new Op(8);
    Base* variable3 = new Op(2);
    
    ListContainer* test = new ListContainer();
    test->add_element(variable1);
    test->add_element(variable2);
    test->add_element(variable3);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 0);
    EXPECT_EQ(test->at(1)->evaluate(), 8);
    EXPECT_EQ(test->at(2)->evaluate(), 2);

    test->set_sort_function(new BubbleSort());
    test->sort();

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 0);
    EXPECT_EQ(test->at(1)->evaluate(), 2);
    EXPECT_EQ(test->at(2)->evaluate(), 8);
}

TEST(SortTest, SelectionSort){
    Op* three = new Op(3);
    Op* four = new Op(4);
    Mult* treeA = new Mult(three, four);

    Op* seven = new Op(7);
    Op* two = new Op(2);
    Add* treeB = new Add(seven, two);

    Op* ten = new Op(10);
    Op* five = new Op(5);
    Sub* treeC = new Sub(ten, five);

    ListContainer* test = new ListContainer();
    test->add_element(treeA);
    test->add_element(treeB);
    test->add_element(treeC);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 12);
    EXPECT_EQ(test->at(1)->evaluate(), 9);
    EXPECT_EQ(test->at(2)->evaluate(), 5);

    test->set_sort_function(new SelectionSort());
    test->sort();

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 5);
    EXPECT_EQ(test->at(1)->evaluate(), 9);
    EXPECT_EQ(test->at(2)->evaluate(), 12);    
}

TEST(SortTest, SelectionSortDecimal) {
    Op* three = new Op(3);
    Op* four = new Op(4);
    Div* treeA = new Div(three, four);

    Op* three = new Op(3.4);
    Op* two = new Op(2.5);
    Add* treeB = new Add(three, two);

    Op* ten = new Op(10.4);
    Op* five = new Op(5.2);
    Sub* treeC = new Sub(ten, five);

    VectorContainer* test = new VectorContainer();
    test->add_element(TreeA);
    test->add_element(TreeB);
    test->add_element(TreeC);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 0.75);
    EXPECT_EQ(test->at(1)->evaluate(), 5.9);
    EXPECT_EQ(test->at(2)->evaluate(), 5.2);

    test->set_sort_function(new SelectionSort());
    test->sort();

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 0.75);
    EXPECT_EQ(test->at(1)->evaluate(), 5.2);
    EXPECT_EQ(test->at(2)->evaluate(), 5.9);
}

#endif //__LIST_TEST_HPP__