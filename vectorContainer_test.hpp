#ifndef VECTORCONTAINER_TEST_HPP
#define VECTORCONTAINER_TEST_HPP

#include "gtest/gtest.h"
#include "vectorContainer.hpp"
#include "op.hpp"
#include "base.hpp"
#include "add.hpp"
#include <iostream>

TEST(vectorContainerTest, testEvaluate){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(variable1);
    test_container->add_element(variable2);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(),1);
    EXPECT_EQ(test_container->at(1)->evaluate(),2); 
}

TEST(vectorContainerTest, testPrint){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(variable1);
    test_container->add_element(variable2);
    ASSERT_EQ(test_container->size(), 2);
    cout << "Answer: " << endl;
    test_container->print();
    cout << "Expected: \nTrees: \n1.000000\n2.000000" << endl; 
}

TEST(vectorContainerTest, testOperators){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    Base* operator1 = new Add(variable1, variable2);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(operator1);
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(),3);
}

TEST(vectorContainerTest, testPrintOperators){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    Base* operator1 = new Add(variable1, variable2);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(operator1);
    ASSERT_EQ(test_container->size(), 1);
    cout << "Answer: " << endl;
    test_container->print();
    cout << "Expected: \nTrees: \n1.000000 + 2.000000 " << endl;
}

TEST(vectorContainerTest, testSwap){
    Base* variable1 = new Op(1);
    Base* variable2 = new Op(2);
    VectorContainer* test_container = new VectorContainer();
    test_container->add_element(variable1);
    test_container->add_element(variable2);
    test_container->swap(0, 1);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(),2);
    EXPECT_EQ(test_container->at(1)->evaluate(),1);
}

#endif
