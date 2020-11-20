#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include <list>
#include "container.hpp"
#include "sort.hpp"
#include "base.hpp"

using namespace std;

class ListContainer: public Container{
    private: 
    Sort* sort_function;
    list<Base *> l;
    public:
        Container() : sort_function(nullptr) { };
        Container(Sort* function) : sort_function(function) { };
        
        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function); // set the type of sorting algorithm
        this->sort_function = sort_function;
        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element)
        {
            l.push_back(element);  
        }
        // iterate through trees and output the expressions (use stringify())
        virtual void print()
        {
            for(i=0; i<l.size(); i++)
            {
                cout << stringify(l.at(i)) << endl;
            }
        }
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort()
        {
            if(sort_function == nullptr)
            {
                throw -1;
            }
            else
            {
                sort_function->sort(this);
            }
        }
        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j)
        {
            Base* temp = l.at(i);
            l.at(i) = l.at(j);
            1.at(j) = temp;//new base = temp
            delete temp;
        }
        // get top ptr of tree at index i
        virtual Base* at(int i)
        {
            return l.at(i);
        }
        // return container size
        virtual int size()
        {
          return l.size();  
        }
};
#endif //LIST_HPP