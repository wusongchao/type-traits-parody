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

template <class T>
T IsIntergralTestf(T i)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	return i;
}

void IsIntergralTest()
{
	class A {};

	std::cout << std::boolalpha;
	std::cout << std::is_integral<A>::value << '\n';
	std::cout << std::is_integral<float>::value << '\n';
	std::cout << std::is_integral<int>::value << '\n';
	std::cout << std::is_integral<bool>::value << '\n';
	std::cout << std::is_integral<unsigned int>::value << '\n';
	std::cout << std::is_integral<uint32_t>::value << '\n';
	std::cout << std::is_integral<const volatile long>::value << '\n';
	std::cout << IsIntergralTestf(123) << '\n';
}

void IsFloatingTest()
{
	class A {};
	static_assert(IsFloatingPoint<A>::value == false, "IsFloatingPoint");
	static_assert(IsFloatingPoint<float>::value, "IsFloatingPoint");
	static_assert(IsFloatingPoint<int>::value == false, "IsFloatingPoint");
	static_assert(IsFloatingPoint<double>::value, "IsFloatingPoint");
	static_assert(IsFloatingPoint<long double>::value, "IsFloatingPoint");
	static_assert(IsFloatingPoint<const long double>::value, "IsFloatingPoint");
}

void IsArrayTest()
{
	class A {};

	static_assert(IsArray<A>::value == false, "IsArray");
	static_assert(IsArray<A[]>::value, "IsArray");
	static_assert(IsArray<A[3]>::value, "IsArray");
	static_assert(IsArray<float>::value == false, "IsArray");
	static_assert(IsArray<int>::value == false, "IsArray");
	static_assert(IsArray<int[]>::value, "IsArray");
	static_assert(IsArray<int[3]>::value, "IsArray");
}

void IsEnumTest()
{
	class A {};

	enum E {};

	enum class Ec : int {};

	std::cout << std::boolalpha;
	std::cout << IsEnum<A>::value << '\n';
	std::cout << IsEnum<E>::value << '\n';
	std::cout << IsEnum<Ec>::value << '\n';
	std::cout << IsEnum<int>::value << '\n';
}

int main()
{
	IsIntergralTest();
	cout << "--------------" << '\n';
	IsEnumTest();
	getchar();
	return 0;
}