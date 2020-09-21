#include "pch.h"
#include "gtest/gtest.h"
#include "..\LAB1B\Nephroid.h"
#include "..\LAB1B\Nephroid.cpp"

TEST(NephroidConstructor, Constructor1) {
	lab1b::Nephroid c1;
	ASSERT_EQ(0, c1.getP().x);
	ASSERT_EQ(0, c1.getP().y);
	ASSERT_EQ(1, c1.getR());
}

TEST(NephroidConstructor, InitConstructors)
{
	lab1b::Nephroid a2(3);
	lab1b::Point p(2, 3);
	ASSERT_EQ(3, a2.getR());
	ASSERT_EQ(0, a2.getP().x);
	ASSERT_EQ(0, a2.getP().y);
	lab1b::Nephroid a3(p, 8);
	ASSERT_EQ(2, a3.getP().x);
	ASSERT_EQ(3, a3.getP().y);
	ASSERT_EQ(8, a3.getR());
	lab1b::Nephroid a4(-4, -5, 3);
	ASSERT_EQ(-4, a4.getP().x);
	ASSERT_EQ(-5, a4.getP().y);
	ASSERT_EQ(3, a4.getR());
}
TEST(NephroidConstructor, TestException)
{
	lab1b::Point p;
	ASSERT_ANY_THROW(lab1b::Nephroid(2, 5, -5));
	ASSERT_ANY_THROW(lab1b::Nephroid(p, -1));
}

TEST(NephroidMethods, Setters)
{
	lab1b::Nephroid a;
	lab1b::Point p1(3, 2);
	a.setP(p1);
	ASSERT_EQ(3, a.getP().x);
	ASSERT_EQ(2, a.getP().y);
	lab1b::Point p2(-3, -2);
	a.setP(p2);
	ASSERT_EQ(-3, a.getP().x);
	ASSERT_EQ(-2, a.getP().y);
	a.setR(2);
	ASSERT_EQ(2, a.getR());
	ASSERT_ANY_THROW(a.setR(-1));
}

TEST(NephroidMethods, Parameters)
{
	lab1b::Nephroid a1;
	const double PI = 3.14159, err = 0.0001;
	ASSERT_NEAR(24, a1.length(), err);
	ASSERT_EQ(0, a1.curveradius());
	ASSERT_EQ(2, a1.coordinates().x);
	ASSERT_EQ(0, a1.coordinates().y);
	ASSERT_NEAR(0, a1.coordinates(PI/2).x, err);
	ASSERT_NEAR(4, a1.coordinates(PI/2).y, err);
	ASSERT_STREQ("(x^2 + y^2 - 4.00)^3 = 108.00*x^2\n", a1.equation());
	lab1b::Nephroid a2(1, 3, 2);
	ASSERT_NEAR(48, a2.length(), err);
	ASSERT_EQ(0, a2.curveradius());
	ASSERT_EQ(5, a2.coordinates().x);
	ASSERT_EQ(3, a2.coordinates().y);
	ASSERT_NEAR(1, a2.coordinates(PI / 2).x, err);
	ASSERT_NEAR(11, a2.coordinates(PI / 2).y, err);
	ASSERT_STREQ("((x - 1.00)^2 + (y - 3.00)^2 - 16.00)^3 = 1728.00*(x - 1.00)^2\n", a2.equation());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}