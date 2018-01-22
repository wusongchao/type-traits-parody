#include "TypeTraits.h"

#include <iostream>

using std::cout;
using std::endl;

void IsVoidTest()
{
	static_assert(IsVoid<int>::value, "IsVoid");
	static_assert(IsVoid<void>::value, "IsVoid");
	static_assert(IsVoid<const void>::value, "IsVoid");
	static_assert(IsVoid<volatile void>::value, "IsVoid");
	static_assert(IsVoid<const volatile void>::value, "IsVoid");
}

void IsNullPointerTest()
{
	static_assert(IsNullPointer<int*>::value, "IsNullPointer");
	static_assert(IsNullPointer<decltype(nullptr)>::value, "IsNullPointer");
}

int main()
{
	IsVoidTest();
	getchar();
	return 0;
}