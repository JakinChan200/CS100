#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "sort.hpp"
#include "container.hpp"
#include <vector>

using namespace std;
class SelectionSort : public Sort {
    public:
        SelectionSort(){};

        virtual void sort(Container* container){
	    int index = 0;
	    int size = container->size();
	    for(int i = 0; i < size-1; i++){
		index = i;
	        for(int j = i+1; j < size; j++){
		    if(container->at(j)->evaluate() < container->at(index)->evaluate()){
		    	index = j;
 		    }
		}
		container->swap(i, index);
	    }
	}
};

#endif
