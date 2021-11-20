#ifndef MOCKCLASSES_HPP
#define MOCKCLASSES_HPP


#include "base.hpp"
#include <string>

using namespace std;

class NegativeOp: public Base{
	public:
		NegativeOp(){}
		virtual double evaluate() {return -7.0;}
		virtual string stringify() {return "-7.0";}
};

class ZeroOp: public Base{
	public:
		ZeroOp(){}
		virtual double evaluate() {return 0.0;}
		virtual string stringify() {return "0.0";}

};

class PositiveOp: public Base{
	public:
		PositiveOp(){}
		virtual double evaluate() {return 5.5;}
		virtual string stringify() {return "5.5";}
};

class PositiveOp2: public Base{
	public:
		PositiveOp2(){}
		virtual double evaluate() {return 4.0;}
		virtual string stringify() {return "4.0";}
};

#endif