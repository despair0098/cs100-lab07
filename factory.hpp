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
		Base* op;
			for(int i = 0; i < length; i++){
				cout << "Indices: " << i << endl; 
				cout <<  input[i] << endl;
				string strc = input[i];
				if(strc == "+"){
					if(i+1 > length){
						cout << "Invalid Input" << endl;
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* add = new Add(op, op2);
					op = add;
					++i;
				} else if(strc == "-"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* sub = new Sub(op, op2);
					op = sub;
					++i;
				} else if(strc == "*"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					cout << "OP in Mult: " + op->stringify() << endl;
					Base* op2 = new Op(stod(input[i+1]));
					cout << "OP2: " + op2->stringify() << endl;
					Base* mult = new Mult(op, op2);
					cout << "Mult: " + mult->stringify() << endl;
					op = mult;
					++i;
				} else if(strc == "**"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* pow = new Pow(op, op2);
					op = pow;
					++i;
				} else if(strc == "/"){
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
					cout << op->evaluate() << endl;
					cout << "OP: " + op->stringify() << endl;
				}
			}
		return op;	
	}
};
