#ifndef ITERATOR_TEST_HPP
#define ITERATOR_TEST_HPP

#include "gtest/gtest.h"
#include "container.hpp"
#include "vectorContainer.hpp"
#include "list.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "iterator.hpp"
#include <vector>
#include <iostream>

using namespace std;

TEST(iteratorTest, basicFuncTest) {
    Op* variable1 = new Op(2);
    Op* variable2 = new Op(4);

    Add* operator1 = new Add(variable1, variable2);
    
    EXPECT_EQ(operator1->evaluate(), 6);
}

TEST(iteratorTest, basicFuncTestCont) {
    Op* variable1 = new Op(2);
    Op* variable2 = new Op(4);

    Add* operator1 = new Add(variable1, variable2);
    PreorderIterator *test = new PreorderIterator(operator1);
    test->first();
    int count = 0;
    while(test->is_done() == false){
        count++;
	cout << "Base Object " << count << "'s value: " << test->current()->evaluate() << endl;
	test->next();
    }
    EXPECT_EQ(count, 2);
}

TEST(iteratorTest, testingMulipleOperators) {
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(4);
    Base* variable3 = new Op(7);

    Base* operator1 = new Add(variable1, variable2);
    Base* dummyNode = new Add(operator1, variable3);
    PreorderIterator *test = new PreorderIterator(dummyNode);
    test->first();
    int count = 0;
    while(test->is_done() == false){
        count++;
        cout << "Base Object " << count << "'s value: " << test->current()->evaluate() << endl;
        test->next();
    }
    EXPECT_EQ(count, 4);
}

#endif
