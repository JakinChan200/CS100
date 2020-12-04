#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

using namespace std;

int main() {
    Base* variable1 = new Op(2);
    Base* variable2 = new Op(3);
    Base* variable3 = new Op(5);
    Base* variable4 = new Op(7);
    Base* variable5 = new Op(1);

    Base* operator1 = new Add(variable1, variable2);
    Base* operator2 = new Sub(variable4, variable3);
    Base* operator3 = new Mult(operator1, operator2);
    Base* operator4 = new Pow(operator3, variable5);
    Base* operator5 = new Div(operator4, variable1);

    Base* dummyNode = new Pow(operator5, variable1);
    
    Iterator* iter = new PreorderIterator(dummyNode);
    CountVisitor* visitor1 = new CountVisitor();

    for(iter->first(); iter->is_done() == false; iter->next()){
	iter->current()->accept(visitor1);
    }

    cout << "Num Op: " << visitor1->op_count() << endl;
    cout << "Num Add: " << visitor1->add_count() << endl;
    cout << "Num Sub: " << visitor1->sub_count() << endl;
    cout << "Num Mult: " << visitor1->mult_count() << endl;
    cout << "Num Div: " << visitor1->div_count() << endl;
    cout << "Num Rand: " << visitor1->rand_count() << endl;
    cout << "Num Pow: " << visitor1->pow_count() << endl;

    return 0;
}
