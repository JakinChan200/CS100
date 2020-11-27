#include <iostream>
#include "factory.hpp"
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
using namespace std;

int main(int argc, char **argv){
    
    Factory* tree = new Factory();
    Base* finalProduct = tree->parse(argv, argc);
    
    if(finalProduct == nullptr){
    	cout << "Expression Invalid or Empty" << endl;
	return 1;
    }
    cout << "Expression String: " << finalProduct->stringify() << endl;
    cout << "Expression Answer: " << finalProduct->evaluate() << endl;
    return 0;
};
