#include "pch.h"
#include "../Header.h"

TEST(BigNumTest, GetSet){
	CBigNumber num(0, 0);
	long long a = 12345;
	long long b = 12345;
	num.SetBigNum(a, b);
	long long value_a;
	unsigned long long value_b;
	num.GetBigNum(value_a, value_b);
	EXPECT_EQ(value_a, a);
	EXPECT_EQ(value_b, b);
}

TEST(BigNumTest, SumaTwoBigNums) {
	CBigNumber num1(100, 25);
	CBigNumber num2(5, 25);
	CBigNumber result = num1.SumBigNums(num2);// call the AddToBigNum function on num1 and pass in num2 as argument
	EXPECT_EQ(result.GetA(), 105);// check if the result is as expected
	EXPECT_EQ(result.GetB(), 50);
}
TEST(BigNumTest, OverflowSum) {
	CBigNumber num1(LLONG_MAX, 1);
	CBigNumber num2(1, 10);
	CBigNumber result = num1.SumBigNums(num2);
	//result.print();
	/*EXPECT_EQ(num1.GetA(), LLONG_MAX);
	EXPECT_EQ(num1.GetB(), 7);*/
	EXPECT_EQ(result.GetA(), LLONG_MAX);
	EXPECT_EQ(result.GetB(),12);
	num1.SetBigNum(3, ULLONG_MAX);
	num2.SetBigNum(10, 5);
	result = num1.SumBigNums(num2);
	EXPECT_EQ(result.GetA(), 18);
	EXPECT_EQ(result.GetB(), ULLONG_MAX);
	result.print();
	/*ASSERT_DEATH({
		CBigNumber result = num1.SumBigNums(num2);
	}, "overflow_blabla.*");*/
}

TEST(BigNumTest, Subtract) {
	CBigNumber num1(2, 100);
	CBigNumber num2(3, 100);
	CBigNumber result = num1.SubtractBigNums(num2);
	ASSERT_EQ(result.GetA(), -1);
	ASSERT_EQ(result.GetB(), 0);
}

TEST(BigNumTest, Subtract2) {
	CBigNumber num1(LLONG_MAX, ULLONG_MAX);
	CBigNumber num2(0, ULLONG_MAX);
	CBigNumber result = num1.SubtractBigNums(num2);
	ASSERT_EQ(result.GetA(), LLONG_MAX);
	ASSERT_EQ(result.GetB(), 0);
}

TEST(BigNumTest, SubtractOverflow) {
	CBigNumber num1(LLONG_MIN, 0);
	CBigNumber num2(1, 0);
	ASSERT_DEATH({
		num1.SubtractBigNums(num2);
	}, "");
}