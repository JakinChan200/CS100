#ifndef __LIST_TEST_HPP__
#define __LIST_TEST_HPP__

#include "gtest/gtest.h"
#include "container.hpp"
#include "list.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "base.hpp"
#include <iostream>
using namespace std;

TEST(ListTest, BasicFunctListTest){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    Base* variable3 = new Op(3);

    ListContainer* test = new ListContainer();
    test->add_element(variable2);
    test->add_element(variable3);
    test->add_element(variable1);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 2);
    EXPECT_EQ(test->at(1)->evaluate(), 3);
    EXPECT_EQ(test->at(2)->evaluate(), 1);
}

TEST(ListTest, Print) {
    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* plus = new Add(one, two);
    Op* three = new Op(3);
    Op* ten = new Op(10);
    Mult* times = new Mult(three, ten);
    ListContainer* test_container = new ListContainer();
    test_container->add_element(plus);
    test_container->add_element(times);
    ASSERT_EQ(test_container->size(), 2);
    cout << "Answer: \nTrees: " << endl;
    cout << "1.000000 + 2.000000" << endl;
    cout << "(3.000000) * (10.000000)" << endl;
    test_container->print();
}

TEST(ListTest, SwapTesting) {
    Op* tenpteight = new Op(10.8);
    Op* hundredandfive = new Op(105);
    ListContainer* test_container = new ListContainer();
    test_container->add_element(tenpteight);
    test_container->add_element(hundredandfive);
    test_container->swap(0,1);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 105);
    EXPECT_EQ(test_container->at(1)->evaluate(), 10.8);
}

TEST(ListTest, BubbleSort) {
    Op* variable1 = new Op(0);
    Op* variable2 = new Op(8);
    Op* variable3 = new Op(2);
    
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

TEST(ListTest, SelectionSort){
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

TEST(ListTest, SelectionSortDecimal) {
    Op* three = new Op(3);
    Op* four = new Op(4);
    Div* treeA = new Div(three, four);

    Op* threePoint = new Op(3.4);
    Op* two = new Op(2.5);
    Add* treeB = new Add(threePoint, two);

    Op* ten = new Op(10.4);
    Op* five = new Op(5.2);
    Sub* treeC = new Sub(ten, five);

    VectorContainer* test = new VectorContainer();
    test->add_element(treeA);
    test->add_element(treeB);
    test->add_element(treeC);

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
