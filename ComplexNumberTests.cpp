#include "pch.h"
#include "CppUnitTest.h"
#include "ComplexNumber.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		const double eps = 1e-5;

		TEST_METHOD(SumTest1)
		{
			ComplexNumber num1(4.13, -3.333);
			ComplexNumber num2(-23, 4);
			ComplexNumber result = num1 + num2;
			Assert::IsTrue(fabs(-18.87 - result.GetReal() < eps));
			Assert::IsTrue(fabs(0.667 - result.GetImaginary() < eps));
		}

		TEST_METHOD(SumTest2) 
		{
			ComplexNumber num1(-54.2, 7);
			ComplexNumber num2(-65.22, -8.6);
			ComplexNumber result = num1 + num2;
			Assert::IsTrue(fabs(-119.42 - result.GetReal() < eps));
			Assert::IsTrue(fabs(-1.6 - result.GetImaginary() < eps));
		}

		TEST_METHOD(DifferenceTest)
		{
			ComplexNumber num1(431, 54.22);
			ComplexNumber num2(40.4, -999);
			ComplexNumber result = num1 - num2;
			Assert::IsTrue(fabs(390.6 - result.GetReal() < eps));
			Assert::IsTrue(fabs(1053.22 - result.GetImaginary() < eps));
		}

		TEST_METHOD(MultiplicationTest)
		{
			ComplexNumber num1(-2, 2);
			ComplexNumber num2(6, 0.1);
			ComplexNumber result = num1 * num2;
			Assert::IsTrue(fabs(-12.2 - result.GetReal() < eps));
			Assert::IsTrue(fabs(11.8 - result.GetImaginary() < eps));
		}

		TEST_METHOD(DivisionTest)
		{
			ComplexNumber num1(-32, 1);
			ComplexNumber num2(5, 0.33);
			ComplexNumber result = num1 / num2;
			Assert::IsTrue(fabs(-6.35909 - result.GetReal() < eps));
			Assert::IsTrue(fabs(0.61970 - result.GetImaginary() < eps));
		}

		TEST_METHOD(MultiplyOperationsTest)
		{
			ComplexNumber num1(-433, 0.4);
			ComplexNumber num2(425, 65);
			ComplexNumber num3(6.4 , 0);
			ComplexNumber result = (num1 * num2) - num1 / num3 + num2;
			Assert::IsTrue(fabs(-183558.34375 - result.GetReal() < eps));
			Assert::IsTrue(fabs(-27910.0625 - result.GetImaginary() < eps));
		}

		TEST_METHOD(GetTest)
		{
			ComplexNumber num(2.2, -5.4);
			Assert::AreEqual(2.2, num.GetReal());
			Assert::AreEqual(-5.4, num.GetImaginary());
		}

		TEST_METHOD(SetTest)
		{
			ComplexNumber num(2.2, -5.4);
			num.SetReal(4.1);
			num.SetImaginary(2.5);
			Assert::AreEqual(4.1, num.GetReal());
			Assert::AreEqual(2.5, num.GetImaginary());
		}
		
		TEST_METHOD(AbsTest)
		{
			ComplexNumber num(3, -4);
			Assert::IsTrue(5 - num.Abs() < eps);
		}

		TEST_METHOD(PowTest1)
		{
			ComplexNumber num(1, 3.3);
			ComplexNumber result = num.Pow(6);
			Assert::IsTrue(325.063531 - result.GetReal() < eps);
			Assert::IsTrue(1649.18358 - result.GetImaginary() < eps);
		}

		TEST_METHOD(PowTest2)
		{
			ComplexNumber num(0, 0);
			ComplexNumber result = num.Pow(4);
			Assert::IsTrue(0 - result.GetReal() < eps);
			Assert::IsTrue(0 - result.GetImaginary() < eps);
		}

		TEST_METHOD(EqualityTest1)
		{
			ComplexNumber num1(3, 2);
			ComplexNumber num2(3, 2);
			Assert::IsTrue(num1 == num2);
		}

		TEST_METHOD(EqualityTest2)
		{
			ComplexNumber num1(1, 2);
			ComplexNumber num2(3, 2);
			Assert::IsFalse(num1 == num2);
		}

		TEST_METHOD(EqualityTest3)
		{
			ComplexNumber num1(3, 2);
			int num2 = 3;
			Assert::IsFalse(num1 == num2);
		}

		TEST_METHOD(EqualityTest4)
		{
			ComplexNumber num1(4, 0);
			int num2 = 4;
			Assert::IsTrue(num1 == num2);
		}

		TEST_METHOD(EqualityTest5)
		{
			ComplexNumber num1(3.2, 2);
			double num2 = 3.2;
			Assert::IsFalse(num1 == num2);
		}

		TEST_METHOD(EqualityTest6)
		{
			ComplexNumber num1(6.4, 0);
			double num2 = 6.4;
			Assert::IsTrue(num1 == num2);
		}

		TEST_METHOD(OverallTest)
		{
			ComplexNumber num(43, -3.42);
			num += *(new ComplexNumber(4.2, 5));
			num = num.Pow(3);
			num -= *new ComplexNumber(600.5, 42.1);
			Assert::IsTrue(104729.14825280505 - num.Abs() < eps);
		}
	};
}
