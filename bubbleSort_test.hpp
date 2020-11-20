#ifndef BUBBLESORT_TEST_HPP
#define BUBBLESORT_TEST_HPP

#include "container.hpp"
#include "vectorContainer.hpp"
#include "bubbleSort.hpp"
#include "list.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "pow.hpp"
#include <vector>
#include <iostream>

using namespace std;

TEST(SortTestSet, BubbleSortVectorTest) {
    Op* five = new Op(2);
    Op* four = new Op(7);
    Mult* TreeA = new Mult(five, four);

    Op* eight = new Op(3);
    Op* two = new Op(4);
    Add* TreeB = new Add(eight, two);

    Op* ten = new Op(10);
    Op* three = new Op(4);
    Sub* TreeC = new Sub(ten, three);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 14);
    EXPECT_EQ(container->at(1)->evaluate(), 7);
    EXPECT_EQ(container->at(2)->evaluate(), 6);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 6);
    EXPECT_EQ(container->at(1)->evaluate(), 7);
    EXPECT_EQ(container->at(2)->evaluate(), 14);
}

TEST(SortTestSet, BubbleSortDecimalVectorTest) {
    Op* five = new Op(5);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(five, four);

    Op* variable3 = new Op(8.3);
    Op* variable4 = new Op(2.7);
    Add* TreeB = new Add(variable3, variable4);

    Op* variable5 = new Op(15.2);
    Op* variable6 = new Op(12.2);
    Sub* TreeC = new Sub(variable5, variable6);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 20);
    EXPECT_EQ(container->at(1)->evaluate(), 11);
    EXPECT_EQ(container->at(2)->evaluate(), 3);
    
    container->set_sort_function(new BubbleSort());
    container->sort();
    
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 3);
    EXPECT_EQ(container->at(1)->evaluate(), 11);
    EXPECT_EQ(container->at(2)->evaluate(), 20);
}

TEST(SortTest, BubbleSortListTest) {
    Op* five = new Op(2);
    Op* four = new Op(7);
    Mult* TreeA = new Mult(five, four);

    Op* eight = new Op(3);
    Op* two = new Op(4);
    Add* TreeB = new Add(eight, two);

    Op* ten = new Op(10);
    Op* three = new Op(4);
    Sub* TreeC = new Sub(ten, three);

    VectorContainer* test = new ListContainer();
    test->add_element(TreeA);
    test->add_element(TreeB);
    test->add_element(TreeC);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 14);
    EXPECT_EQ(test->at(1)->evaluate(), 7);
    EXPECT_EQ(test->at(2)->evaluate(), 6);

    test->set_sort_function(new BubbleSort());
    test->sort();

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 6);
    EXPECT_EQ(test->at(1)->evaluate(), 7);
    EXPECT_EQ(test->at(2)->evaluate(), 14);
}

TEST(SortTest, BubbleSortDecimalListTest) {
    Op* five = new Op(5);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(five, four);

    Op* variable3 = new Op(8.3);
    Op* variable4 = new Op(2.7);
    Add* TreeB = new Add(variable3, variable4);

    Op* variable5 = new Op(15.2);
    Op* variable6 = new Op(12.2);
    Sub* TreeC = new Sub(variable5, variable6);

    VectorContainer* test = new ListContainer();
    test->add_element(TreeA);
    test->add_element(TreeB);
    test->add_element(TreeC);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 20);
    EXPECT_EQ(test->at(1)->evaluate(), 11);
    EXPECT_EQ(test->at(2)->evaluate(), 3);
    
    test->set_sort_function(new BubbleSort());
    test->sort();
    
    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 3);
    EXPECT_EQ(test->at(1)->evaluate(), 11);
    EXPECT_EQ(test->at(2)->evaluate(), 20);
}
#endif //__BUBBLESORT_TEST_HPP__
