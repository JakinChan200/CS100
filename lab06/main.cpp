#include <iostream>
#include "container.hpp"
#include "sort.hpp"
#include "vectorContainer.hpp"
#include "selectionSort.hpp"
#include "bubbleSort.hpp"
#include "list.hpp"
#include "add.hpp"
#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <string>

using namespace std;

int main (){
   Base* three = new Op(3);
   Base* seven = new Op(7);
   Base* four = new Op(4);
   Base* two = new Op(2);
   Base* mult = new Mult(seven, four);
   Base* add = new Add(three, mult);
   Base* minus = new Sub(add, two);	
   cout << "Equation1: " << minus->stringify() << " = " << minus->evaluate() << endl;
      
   Base* one = new Op(1);
   Base* five = new Op(5);
   Base* six = new Op(6);
   Base* randDouble = new Rand();
   Base* pow = new Pow(five, six);
   Base* subtraction = new Sub(pow, one);
   Base* addition = new Add(subtraction, randDouble);
   cout << "Equation2: " << addition->stringify() << " = " << addition->evaluate() << endl;

   Base* eight = new Op(8);
   Base* nine = new Op(9);
   Base* ten = new Op(10);
   Base* division = new Div(ten, eight);
   Base* plus = new Add(division, nine);
   cout << "Equation3: " << plus->stringify() << " = " << plus->evaluate() << endl;

   VectorContainer* container1 = new VectorContainer();
   VectorContainer* container2 = new VectorContainer();
	
   container1->add_element(minus);  
   container1->add_element(addition);
   container1->add_element(plus);

   container2->add_element(minus);
   container2->add_element(addition);
   container2->add_element(plus);

   ListContainer* container3 = new ListContainer();
   ListContainer* container4 = new ListContainer();

   container3->add_element(minus);
   container3->add_element(addition);
   container3->add_element(plus);

   container4->add_element(minus);
   container4->add_element(addition);
   container4->add_element(plus);

   container1->set_sort_function(new SelectionSort());
   container2->set_sort_function(new BubbleSort());
   container3->set_sort_function(new SelectionSort());
   container4->set_sort_function(new BubbleSort());

   container1->sort();
   container2->sort();
   container3->sort();
   container4->sort();
   
   cout << endl;

   cout << "Vector Container x Selection Sort: " << 
	container1->at(0)->evaluate() << ", " <<
	container1->at(1)->evaluate() << ", " <<
	container1->at(2)->evaluate() << endl;
	
   cout << "Vector Container x Bubble Sort: " <<
        container2->at(0)->evaluate() << ", " <<
        container2->at(1)->evaluate() << ", " <<
        container2->at(2)->evaluate() << endl;

   cout << "List Container x Selection Sort: " <<
        container3->at(0)->evaluate() << ", " <<
        container3->at(1)->evaluate() << ", " <<
        container3->at(2)->evaluate() << endl;

   cout << "List Container x Bubble Sort: " <<
        container4->at(0)->evaluate() << ", " <<
        container4->at(1)->evaluate() << ", " <<
        container4->at(2)->evaluate() << endl;

   return 0;
}
