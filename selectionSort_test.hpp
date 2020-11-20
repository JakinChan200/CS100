#include "gtest/gtest.h"
#include "container.hpp"
#include "selectionSort.hpp"
#include "vectorContainer.hpp"
#include "list.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "base.hpp"
#include <iostream>

TEST(SortTestSet, BasicFunctTest){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    Base* variable3 = new Op(3);

    VectorContainer* container = new VectorContainer();
    container->add_element(variable2);
    container->add_element(variable3);
    container->add_element(variable1);
    
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 2);
    EXPECT_EQ(container->at(1)->evaluate(), 3);
    EXPECT_EQ(container->at(2)->evaluate(), 1);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 1);
    EXPECT_EQ(container->at(1)->evaluate(), 2);
    EXPECT_EQ(container->at(2)->evaluate(), 3);   
}

TEST(SortTestSet, SelectionSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, SelectionSortDecimalTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3.4);
    Op* two = new Op(2.5);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10.4);
    Op* six = new Op(6.2);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5.9);
    EXPECT_EQ(container->at(2)->evaluate(), 4.2);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4.2);
    EXPECT_EQ(container->at(1)->evaluate(), 5.9);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, BasicFunctListTest){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    Base* variable3 = new Op(3);

    VectorContainer* test = new ListContainer();
    test->add_element(variable2);
    test->add_element(variable3);
    test->add_element(variable1);
    
    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 2);
    EXPECT_EQ(test->at(1)->evaluate(), 3);
    EXPECT_EQ(test->at(2)->evaluate(), 1);

    test->set_sort_function(new SelectionSort());
    test->sort();

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 1);
    EXPECT_EQ(test->at(1)->evaluate(), 2);
    EXPECT_EQ(test->at(2)->evaluate(), 3);   
}

TEST(SortTest, SelectionListTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* test = new ListContainer();
    test->add_element(TreeA);
    test->add_element(TreeB);
    test->add_element(TreeC);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 28);
    EXPECT_EQ(test->at(1)->evaluate(), 5);
    EXPECT_EQ(test->at(2)->evaluate(), 4);

    test->set_sort_function(new SelectionSort());
    test->sort();

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 4);
    EXPECT_EQ(test->at(1)->evaluate(), 5);
    EXPECT_EQ(test->at(2)->evaluate(), 28);
}

TEST(SortTest, SelectionListDecimalTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3.4);
    Op* two = new Op(2.5);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10.4);
    Op* six = new Op(6.2);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new ListContainer();
    test->add_element(TreeA);
    test->add_element(TreeB);
    test->add_element(TreeC);

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 28);
    EXPECT_EQ(test->at(1)->evaluate(), 5.9);
    EXPECT_EQ(test->at(2)->evaluate(), 4.2);

    test->set_sort_function(new SelectionSort());
    test->sort();

    ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 4.2);
    EXPECT_EQ(test->at(1)->evaluate(), 5.9);
    EXPECT_EQ(test->at(2)->evaluate(), 28);
}
#endif //__SELECTIONSORT_TEST_HPP__