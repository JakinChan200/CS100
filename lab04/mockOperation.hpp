#ifndef MOCK_OPERATOR_HPP
#define MOCK_OPERATOR_HPP

using namespace std;

class MockOperator: public Base {
    public:
        MockOperator(Base* num1, Base* num2) { 
            left = num1;
	    right = num2;
        };

        double evaluate() { 
	    return left->evaluate() + right->evaluate();
	}
        string stringify() { 
	    return to_string(left->evaluate()) + " + " + to_string(right->evaluate()) + " "; 
	}
    private:
        Base* left = nullptr;
	Base* right = nullptr;

};


#endif
