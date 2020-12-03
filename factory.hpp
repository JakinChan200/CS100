#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Factory {
    private:
	Base* root = nullptr;
    public:
	Factory(){};
    
	Base* parse(char** input, int length){
	    if((length-1)%2 != 1){
    	        return nullptr;
		}
	    
	    double temp = stod(input[1]);
	    root = new Op(temp);
	    
	    for(int i = 2; i < length; i+=2){
		string strOper = input[i];
		Base* tempOperator = nullptr;		

		temp = stod(input[i+1]);
		Base* tempOperand = new Op(temp);

		if(strOper == "+"){
            tempOperator = new Add(root, tempOperand);
		}
		else if(strOper == "-"){
            tempOperator = new Sub(root, tempOperand);
		}else if(strOper == "*"){
            tempOperator = new Mult(root, tempOperand);
		}else if(strOper == "/"){
            tempOperator = new Div(root, tempOperand);
		}else if(strOper == "**"){
            tempOperator = new Pow(root, tempOperand);
		}else{
			return nullptr;
		}
		root = tempOperator;
		tempOperator = nullptr;
		tempOperand = nullptr;
	    }
	    return root;	
	}
};

#endif
