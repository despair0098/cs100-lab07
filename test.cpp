#include "gtest/gtest.h"

#include "op.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "MockClasses.hpp"
#include "factory.hpp"

using namespace std;

TEST(Factory, Add) {
    char* test_val[2]; test_val[0] = (char*)"3"; test_val[1] = (char*)"+"; test_val[2] = (char*)"2";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 2);
    EXPECT_EQ("((3.000000)+(2.000000))", test->stringify());
    EXPECT_EQ(5.000000, test->evaluate());
}

TEST(Factory, AddAndSub) {
    char* test_val[5]; test_val[0] = (char*)"3"; test_val[1] = (char*)"+" ; test_val[2] = (char*)"2"; test_val[3] = (char*)"-"; test_val[4] = (char*)"5";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 5);
    string result1 = test->stringify();
    double result2 = test->evaluate();
    EXPECT_EQ("(((3.000000)+(2.000000))-(5.000000))", result1);
    EXPECT_EQ(0.000000, result2);
}

TEST(Factory, Multiplication) {
    char* test_val[2]; test_val[0] = (char*)"10"; test_val[1] = (char*)"*"; test_val[2] = (char*)"2";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 2);
    string result1 = test->stringify();
    double result2 = test->evaluate();
    EXPECT_EQ("((10.000000)*(2.000000))", result1);
    EXPECT_EQ(20.000000, result2);
}

TEST(Factory, Division) {
    char* test_val[2]; test_val[0] = (char*)"10"; test_val[1] = (char*)"/"; test_val[2] = (char*)"2";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 2);
    string result1 = test->stringify();
    double result2 = test->evaluate();
    EXPECT_EQ("((10.000000)/(2.000000))", result1);
    EXPECT_EQ(5.000000, result2);
}

TEST(Factory, Power) {
    char* test_val[2]; test_val[0] = (char*)"0"; test_val[1] = (char*) "**"; test_val[2] = (char*)"2";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 2);
    string result1 = test->stringify();
    double result2 = test->evaluate();
    EXPECT_EQ("((0.000000)**(2.000000))", result1);
    EXPECT_EQ(0.000000, result2);
}

TEST(Factory, Invalid) {
    char* test_val[2]; test_val[0] = (char*)"Hello"; test_val[1] = (char*)"World"; test_val[2] = (char*)"Something";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 2);
    string result1 = test->stringify();
    double result2 = test->evaluate();
    EXPECT_EQ("(0.000000)", result1);
    EXPECT_EQ(0.000000, result2);
}

TEST(Factory, CombinedFunctions) {
    char* test_val[8]; test_val[0] = (char*)"3"; test_val[1] = (char*)"+" ; test_val[2] = (char*)"2"; test_val[3] = (char*)"-"; test_val[4] = (char*)"5"; test_val[5] = (char*)"+"; test_val[6] = (char*)"3.5"; test_val[7] = (char*)"*"; test_val[8] = (char*)"2";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 8);
    string result1 = test->stringify();
    double result2 = test->evaluate();
    EXPECT_EQ("(((((3.000000)+(2.000000))-(5.000000))+(3.500000))*(2.000000))", result1);
    EXPECT_EQ(7.000000, result2);
}

TEST(Mult1, OpNegativeAndPositive) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp();
    Base* mult = new Mult(test1, test2);
    EXPECT_EQ(mult->evaluate(),- 38.5);
    EXPECT_EQ(mult->stringify(), "(-7.0*5.5)");
}

TEST(Mult2, OpZeroAndNegative) {
    Base* test1 = new ZeroOp();
    Base* test2 = new NegativeOp();
    Base* mult = new Mult(test1, test2);    
    EXPECT_EQ(mult->evaluate(), 0);
    EXPECT_EQ(mult->stringify(), "(0.0*-7.0)");
}

TEST(Div1, OpNegativeAndZeroBottom) {
    Base* test1 = new NegativeOp();
    Base* test2 = new ZeroOp();
    Base* div = new Div(test1, test2);
    EXPECT_EQ(div->evaluate(), 0);
    EXPECT_EQ(div->stringify(), "Undefined");
}

TEST(Div2, OpZeroTopAndPositive) {
    Base* test1 = new ZeroOp();
    Base* test2 = new PositiveOp();
    Base* div = new Div(test1, test2);
    EXPECT_EQ(div->evaluate(),0);
    EXPECT_EQ(div->stringify(), "(0.0/5.5)");
}

TEST(Div3, OpPos2AndNeg) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp2();
    Base* div = new Div(test1, test2);    
    EXPECT_EQ(div->evaluate(), -1.75);
    EXPECT_EQ(div->stringify(), "(-7.0/4.0)");
}

TEST(Sub1, OpZeroAndNegative) {
    Base* test1 = new ZeroOp();
    Base* test2 = new NegativeOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), 7.0);
    EXPECT_EQ(sub->stringify(), "(0.0--7.0)");
}

TEST(Sub2, OpZeroAndPositive) {
    Base* test1 = new ZeroOp();
    Base* test2 = new PositiveOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), -5.5);
    EXPECT_EQ(sub->stringify(), "(0.0-5.5)");
}

TEST(Sub3, OpPosAndNeg) {
    Base* test1 = new PositiveOp();
    Base* test2 = new NegativeOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), 12.5);
    EXPECT_EQ(sub->stringify(), "(5.5--7.0)");
}

TEST(Sub4, OpNegAndPos) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp();
    Base* sub = new Sub(test1, test2);    
    EXPECT_EQ(sub->evaluate(), -12.5);
    EXPECT_EQ(sub->stringify(), "(-7.0-5.5)");
}

TEST(Add1, OpPosAndNegative) {
    Base* test1 = new PositiveOp();
    Base* test2 = new NegativeOp();
    Base* add = new Add(test1, test2);    
    EXPECT_EQ(add->evaluate(), -1.5);
    EXPECT_EQ(add->stringify(), "(5.5+-7.0)");
}

TEST(Pow1, OpNegAndZero) {
    Base* test1 = new NegativeOp();
    Base* test2 = new ZeroOp();
    Base* pow = new Pow(test1, test2);    
    EXPECT_EQ(pow->evaluate(), 1);
    EXPECT_EQ(pow->stringify(), "(-7.0**0.0)");
}

TEST(Pow2, OpPosAndPos2) {
    Base* test1 = new PositiveOp();
    Base* test2 = new PositiveOp2();
    Base* pow = new Pow(test1, test2);    
    EXPECT_EQ(pow->evaluate(), 915.0625);
    EXPECT_EQ(pow->stringify(), "(5.5**4.0)");
}

TEST(Pow3, OpNegAndPos2) {
    Base* test1 = new NegativeOp();
    Base* test2 = new PositiveOp2();
    Base* pow = new Pow(test1, test2);    
    EXPECT_EQ(pow->evaluate(), 2401);
    EXPECT_EQ(pow->stringify(), "(-7.0**4.0)");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
