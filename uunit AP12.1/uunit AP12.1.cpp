#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
struct Elem
{
	Elem* link1,
		* link2;
	int info;
};


namespace uunitAP121
{
	TEST_CLASS(uunitAP121)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* p;

			//1
			p = new Elem; // 1
			p->info = 1; // 2
			Assert::AreEqual(1, p->info);

			//2
			p->link1 = new Elem; // 3
			p->link1->info = 2; // 4
			Assert::AreEqual(2, p->link1->info);

			//3
			p->link2 = new Elem; // 5
			p->link2->info = 3; // 6
			p->link2->link1 = p->link1; // 7
			Assert::AreEqual(3, p->link2->info);
			Assert::IsTrue(p->link2->link1 == p->link1);

			//2
			p->link1->link2 = p->link2; // 8
			Assert::IsTrue(p->link1->link2 == p->link2);

			//4
			p->link1->link1 = new Elem; // 9
			p->link1->link1->info = 4; //10
			p->link1->link1->link1 = p; //11
			Assert::AreEqual(4, p->link1->link1->info);
			Assert::IsTrue(p->link1->link1->link1 == p);

			p->link2->link2 = p->link1->link1->link2; //12
			Assert::IsTrue(p->link2->link2 == p->link1->link1->link2);

			//4
			p->link1->link1->link2 = p->link1; // 13
			Assert::IsTrue(p->link1->link1->link2 == p->link1);

			delete p->link1->link1; // 14
			delete p->link1; // 15
			delete p->link2; // 16
			delete p; // 17
		}
	};
}
