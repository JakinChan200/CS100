#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "sort.hpp"
#include "container.hpp"
#include <iostream>
using namespace std;

class BubbleSort : public Sort{
    public:
        /* Constructors */
        BubbleSort(){};

        /* Pure Virtual Functions */
        virtual void sort(Container* container){
	    for(int i = 0; i < container->size()-1; i++){
	        for(int j = 0; j < container->size()-i-1; j++){
			if(container->at(j)->evaluate() > container->at(j+1)->evaluate()){
			    container->swap(j, j+1);
			}
		}
	    }
	}
};

#endif
