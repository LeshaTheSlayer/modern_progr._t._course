#include "stdafx.h"
#include "CppUnitTest.h"
#include "../memory/TMemory.h"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace memtest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			TMemory<double> test = TMemory<double>();	
			Assert::IsFalse(test.getFState());
			Assert::IsTrue(test.getFNumber() == int());
		}

		TEST_METHOD(store)
		{
			TMemory<std::string> test = TMemory<std::string>();
			std::string testNumber = "string";
			test.store(testNumber);
			Assert::AreEqual(std::string("string"), test.getFNumber());
			Assert::IsTrue(test.getFState());
		}

		TEST_METHOD(add)
		{
			double testNumberFirst = 23.4, testNumberSecond = 16.2;
			TMemory<double> test = TMemory<double>(testNumberFirst);
			test.add(testNumberSecond);
			Assert::AreEqual(testNumberFirst + testNumberSecond, test.getFNumber(), 2);
		}

		TEST_METHOD(clear)
		{
			TMemory<int> test = TMemory<int>(2);
			Assert::IsTrue(test.getFState());
			test.clear();
			Assert::IsFalse(test.getFState());
		}

		TEST_METHOD(read_string)
		{
			TMemory<int> test = TMemory<int>();
			std::string offStr = "_Off";
			Assert::AreEqual(offStr, test.readFState());
			test.store(10);
			std::string onStr = "_On";
			Assert::AreEqual(onStr, test.readFState());
			
		}
	};
}