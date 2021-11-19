#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "factory.hpp"

int main(int argc, char** argv) {
   Factory* factory = new Factory();
   Base* op = factory->parse(argv, argc);
   if(op == nullptr){
       return 1;
   }
   std::cout << op->stringify() << " = " << op->evaluate() << std::endl;
    return 0;
}
