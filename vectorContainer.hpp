#ifndef VECTORCONTAINER
#define VECTORCONTAINER

#include "sort.hpp"
#include "container.hpp"
#include "base.hpp"
#include <iostream>
#include <vector>

using namespace std;

class VectorContainer : public Container {
    private:
	vector<Base*> expressions;
    public:
	VectorContainer(){
	    sort_function = nullptr;
	}

	void add_element(Base* element){
	    expressions.push_back(element); 
	}
	
	void print(){
	    cout << "Trees: " << endl;
	    for(auto tree: expressions){
	    	cout << tree->stringify() << endl;
	    }
	}
	
	void sort(){
	    if(sort_function == nullptr){
	    	throw string ("No sorting Algorithmn found");
	    }else{
		sort_function->sort(this);
	    }
	}
	
	void swap(int i, int j) {
	    Base* temp = expressions[i];
	    expressions[i] = expressions[j];
	    expressions[j] = temp;
	}

	Base* at(int i){
	    if(i < 0 || i >= size()){
	    	throw string ("Out of Bounds error");
	    }
	    return expressions[i];
	}
	
	int size(){
	    return expressions.size();
	}
};
#endif 
