#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "Div.hpp"

using namespace std;


class Factory{
	
	Base* parse(char** input, int length){
		Base* op;
			for(int i = 0; i < length; i++){
				if(input[i] == "+"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* add = new Add(op, op2);
					op = new Op(add->evaluate());
				} else if(input[i] == "-"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* sub = new Sub(op, op2);
					op = new Op(sub->evaluate());
				} else if(input[i] == "\*"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* mult = new Mult(op, op2);
					op = new Op(mult->evaluate());
				} else if(input[i] == "\*\*"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* pow = new Pow(op, op2);
					op = new Op(pow->evaluate());
				} else if(input[i] == "/"){
					if(i+1 > length){
						return nullptr;
						break;
					}
					Base* op2 = new Op(stod(input[i+1]));
					Base* div = new Div(op, op2);
					op = new Op(div->evaluate());
				} else {
					op = new Op(stod(input[i]));
				}
			}
		return op;	
	}
};
