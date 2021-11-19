#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "Div.hpp"
#include <iostream>

using namespace std;


class Factory{
	public: 
	Base* parse(char** input, int length){
		Base* op = new Op();
			for(int i = 0; i < length; i++){
				if(input[i] == "+"){
					if(i+1 > length){
						cout << "Invalid Input" << endl;
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* add = new Add(op, op2);
					op = add;
					++i;
				} else if(input[i] == "-"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* sub = new Sub(op, op2);
					op = sub;
					++i;
				} else if(input[i] == "*"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					cout << op->evaluate() << endl;
					Base* op2 = new Op(stod(input[i+1]));
					cout << op2->evaluate() << endl;
					Base* mult = new Mult(op, op2);
					cout << mult->evaluate() << endl;
					op = mult;
					++i;
				} else if(input[i] == "**"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* pow = new Pow(op, op2);
					op = pow;
					++i;
				} else if(input[i] == "/"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* div = new Div(op, op2);
					op = div;
					++i;
				}else {
					op = new Op(strtod(input[i], input));
				}
			}
		return op;	
	}
};
