#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include <list>
#include "container.hpp"
#include "sort.hpp"
#include "base.hpp"
#include "algorithm"

using namespace std;

class ListContainer: public Container{
    private: 
    list<Base *> l;
    public:
	ListContainer(Sort* funct){
	    sort_function = funct;
	};
	ListContainer(): Container(){};
        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element){
            l.push_back(element);  
        }
        // iterate through trees and output the expressions (use stringify())
        virtual void print(){
	    cout << "Trees: " << endl;
            for(list<Base*>::iterator item = l.begin(); item != l.end(); item++){
                cout << (*item)->stringify() << endl;
            }
        }
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort()
        {
            if(sort_function == nullptr)
            {
                throw string("Invalid sort function");;
            }
            else
            {
                sort_function->sort(this);
            }
        }
        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j){
            auto first = std::next(l.begin(), i);
            auto second = std::next(l.begin(), j);
            std::iter_swap(first, second);
        }
        // get top ptr of tree at index i
        virtual Base* at(int i){
	    if(i < 0){
		throw string("Out of Bounds error: less than Zero");
	    }
	    int counter = 0;
            for(list<Base*>::iterator item = l.begin(); item != l.end(); item++){
		if(counter == i){
		    return *item;
		}
		counter++;
	    }
	    throw string("Out of Bounds error: larger than list size");
        }
        // return container size
        virtual int size(){
            int counter = 0;
	    for(list<Base*>::iterator item = l.begin(); item != l.end(); item++){
	        counter++;
	    }
	    return counter;  
        }
};
#endif //LIST_HPP
