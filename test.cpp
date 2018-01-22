#include "TypeTraits.h"

#include <iostream>

using std::cout;
using std::endl;

void IsSameTest()
{

}

void RemoveCvTest()
{

}

void IsVoidTest()
{
	static_assert(IsVoid<int>::value == false, "IsVoid");
	static_assert(IsVoid<void>::value, "IsVoid");
	static_assert(IsVoid<const void>::value, "IsVoid");
	static_assert(IsVoid<volatile void>::value, "IsVoid");
	static_assert(IsVoid<const volatile void>::value, "IsVoid");
}

void IsNullPointerTest()
{
	static_assert(IsNullPointer<int*>::value == false, "IsNullPointer");
	static_assert(IsNullPointer<decltype(nullptr)>::value, "IsNullPointer");
	static_assert(IsNullPointer<const nullptr_t>::value, "IsNullPointer");
	static_assert(IsNullPointer<volatile nullptr_t>::value, "IsNullPointer");
	static_assert(IsNullPointer<const volatile nullptr_t>::value, "IsNullPointer");
}

int main()
{
	IsVoidTest();
	getchar();
	return 0;
}