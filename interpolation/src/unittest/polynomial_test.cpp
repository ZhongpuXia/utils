#include "polynomial.h"

#include "gtest/gtest.h"

namespace planning {

TEST(PolynomialTest, evaluate) {
    Polynomial func;  //f(x)
    EXPECT_EQ(func(0.0), 0.0);
    EXPECT_EQ(func(1.0), 0.0);
    EXPECT_EQ(func.order(), 0);

    Polynomial func0({2.0});  //f(x) = 2.0
    EXPECT_EQ(func0(0.0), 2.0);
    EXPECT_EQ(func0(1.0), 2.0);
    EXPECT_EQ(func0.order(), 0);

    Polynomial func1({1.0, 2.0});  //f(x) = x + 2
    EXPECT_EQ(func1(0.0), 2.0);
    EXPECT_EQ(func1(1.0), 3.0);
    EXPECT_EQ(func1.order(), 1);

    Polynomial func2({3.0, 1.0, 2.0});  //f(x) = 3x^2 + x + 2
    EXPECT_EQ(func2(0.0), 2.0);
    EXPECT_EQ(func2(1.0), 6.0);
    EXPECT_EQ(func2(10.0), 312.0);
    EXPECT_EQ(func2.order(), 2);

    Polynomial func3({-3.0, 1.0, 2.0});  //f(x) = -3x^2 + x + 2
    EXPECT_EQ(func3(0.0), 2.0);
    EXPECT_EQ(func3(1.0), 0.0);
    EXPECT_EQ(func3(10.0), -288.0);
    EXPECT_EQ(func3.order(), 2);

    Polynomial func_0({0.0, 0.0, 0.0, 0.0}); // f(x) = 0.0
    EXPECT_EQ(func_0(0.0), 0.0);
    EXPECT_EQ(func_0.order(), 0);

    Polynomial func_1({0.0, 0.0, 0.0, 1.0}); // f(x) = 1.0
    EXPECT_EQ(func_1(0.0), 1.0);
    EXPECT_EQ(func_1.order(), 0);

}

TEST(PolynomialTest, derive) {
    Polynomial func;  //f(x)
    EXPECT_EQ(func.derive()(0.0), 0.0);
    EXPECT_EQ(func.derive()(1.0), 0.0);

    Polynomial func0({2.0});  //f(x) = 2.0
    EXPECT_EQ(func0.derive()(0.0), 0.0);
    EXPECT_EQ(func0.derive()(1.0), 0.0);

    Polynomial func1({1.0, 2.0});  //f(x) = x + 2
    EXPECT_EQ(func1.derive()(0.0), 1.0);
    EXPECT_EQ(func1.derive()(1.0), 1.0);

    Polynomial func2({3.0, 1.0, 2.0});  //f(x) = 3x^2 + x + 2
    EXPECT_EQ(func2.derive()(0.0), 1.0);
    EXPECT_EQ(func2.derive()(1.0), 7.0);
    EXPECT_EQ(func2.derive()(10.0), 61.0);

    Polynomial func3({-3.0, 1.0, 2.0});  //f(x) = -3x^2 + x + 2
    EXPECT_EQ(func3.derive()(0.0), 1.0);
    EXPECT_EQ(func3.derive()(1.0), -5.0);
    EXPECT_EQ(func3.derive()(10.0), -59.0);
}

TEST(PolynomialTest, integrate) {
    Polynomial func;  //f(x)
    EXPECT_EQ(func.integrate()(0.0), 0.0);
    EXPECT_EQ(func.integrate()(1.0), 0.0);

    Polynomial func0({2.0});  //f(x) = 2.0
    EXPECT_EQ(func0.integrate()(0.0), 0.0);
    EXPECT_EQ(func0.integrate()(1.0), 2.0);

    Polynomial func1({1.0, 2.0});  //f(x) = x + 2
    EXPECT_EQ(func1.integrate()(0.0), 0.0);
    EXPECT_EQ(func1.integrate()(1.0), 2.5);

    Polynomial func2({3.0, 1.0, 2.0});  //f(x) = 3x^2 + x + 2
    EXPECT_EQ(func2.integrate()(0.0), 0.0);
    EXPECT_EQ(func2.integrate()(1.0), 3.5);
    EXPECT_EQ(func2.integrate()(10.0), 1070);

    Polynomial func3({-3.0, 1.0, 2.0});  //f(x) = -3x^2 + x + 2
    EXPECT_EQ(func3.integrate()(0.0), 0.0);
    EXPECT_EQ(func3.integrate()(1.0), 1.5);
    EXPECT_EQ(func3.integrate()(10.0), -930.0);
}

} // end of planning

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

