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
	    if((length-1)%2 != 1){ return nullptr;}
	    
	    string temp2 = input[1];
	    if(!checkNumber(temp2)){return nullptr;}
	    
	    double temp = stod(input[1]);
	    root = new Op(temp);
	    
	    for(int i = 2; i < length; i+=2){
		string strOper = input[i];
		Base* tempOperator = nullptr;		
	   	
		string temp1 = input[i+1];
		if(!checkNumber(temp1)){ return nullptr;}

		temp = stod(input[i+1]);
		Base* tempOperand = new Op(temp);

		if(strOper == "+"){
            	    tempOperator = new Add(root, tempOperand);
		}else if(strOper == "-"){
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
	
	bool checkNumber(string num){
	    int counter = 0;
	    for(int j = 0; j < num.size(); j++){
                if(!(num[j] <= 57 && num[j] >= 48) && !(num[j] == 43) && !(num[j] == 45) && !(num[j] == 46)){
                    return false;
                }else if(num[j] == 46){
		    counter++;
		}
            }
	    if(counter > 1){
		return false;
	    }
	    return true;
	}
};

#endif
