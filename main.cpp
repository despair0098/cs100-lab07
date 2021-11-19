#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "factory.hpp"

int main(char** argv, int argc) {
   Factory* factory = new Factory();
   Base* op = factory->parse(argv, argc);
   std::cout << op->stringify() << " = " << op->evaluate() << std::endl;
    return 0;
}
