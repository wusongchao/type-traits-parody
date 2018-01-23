#pragma once
#include <type_traits>

using std::nullptr_t;

// https://msdn.microsoft.com/en-us/library/ms177194%28v=vs.140%29.aspx

struct TrueType {
	constexpr static bool value = true;
};

struct FalseType {
	constexpr static bool value = false;
};

// If T and U name the same type with the same const-volatile qualifications, 
// provides the member constant value equal to true. 
// Otherwise value is false.
template
<typename T, typename U>
struct IsSame : FalseType{
};

template
<typename T>
struct IsSame<T, T> : TrueType {
};

// Provides the member typedef type which is the same as T, 
// except that its topmost cv - qualifiers are removed.
// 1) removes the topmost const, the topmost volatile, or both, if present.
// 2) removes the topmost const
// 3) removes the topmost volatile

template
<typename T>
struct RemoveConst {
	typedef T type;
};

template
<typename T>
struct RemoveConst<const T> {
	typedef T type;
};

template
<typename T>
struct RemoveVolatile {
	typedef T type;
};

template
<typename T>
struct RemoveVolatile<volatile T> {
	typedef T type;
};

// nested dependent name
template
<typename T>
struct RemoveCv {
	typedef typename RemoveVolatile<
		typename RemoveConst<T>::type
	>::type type;
};


// Checks whether T is a void type. 
// Provides the member constant value that is equal to true, 
// if T is the type void, const void, volatile void, or const volatile void. 
// Otherwise, value is equal to false.
template
<typename T>
struct IsVoid : IsSame<void, typename RemoveCv<T>::type>{
};

// something about const void
// https://stackoverflow.com/questions/37881240/what-is-const-void/37881363


// Checks whether T is the type std::nullptr_t.
// Provides the member constant value that is equal to true, 
// if T is the type std::nullptr_t, const std::nullptr_t, volatile std::nullptr_t, or const volatile std::nullptr_t.
// Otherwise, value is equal to false.
template
<typename T>
struct IsNullPointer : IsSame<nullptr_t, typename RemoveCv<T>::type> {
};

// Checks whether T is an integral type. 
// Provides the member constant value which is equal to true, 
// if T is the type bool, char, char16_t, char32_t, wchar_t, short, int, long, long long, 
// or any implementation-defined extended integer types, 
// including any signed, unsigned, and cv-qualified variants. 
// Otherwise, value is equal to false.
template
<typename T>
struct _IsIntergralBase : FalseType {
};

template 
<>
struct _IsIntergralBase <bool> : TrueType {
};

template
<>
struct _IsIntergralBase <char> : TrueType {
};

template
<>
struct _IsIntergralBase <unsigned char> : TrueType {
};

template
<>
struct _IsIntergralBase <char16_t> : TrueType {
};

template
<>
struct _IsIntergralBase <char32_t> : TrueType {
};

template
<>
struct _IsIntergralBase <wchar_t> : TrueType {
};

template
<>
struct _IsIntergralBase <short> : TrueType {
};

template
<>
struct _IsIntergralBase <unsigned short> : TrueType {
};

// type like uint8_t int16_t..... are not basic type
// http://en.cppreference.com/w/cpp/types/integer
// http://en.cppreference.com/w/cpp/language/types
template
<>
struct _IsIntergralBase <int> : TrueType {
};

template
<>
struct _IsIntergralBase <unsigned int> : TrueType {
};

template
<>
struct _IsIntergralBase <long> : TrueType {
};

template
<>
struct _IsIntergralBase <unsigned long> : TrueType {
};

template
<>
struct _IsIntergralBase <long long> : TrueType {
};

template
<>
struct _IsIntergralBase<unsigned long long> : TrueType {
};

template
<typename T>
struct IsIntergral : _IsIntergralBase<typename RemoveCv<T>::type> {
};

// Checks whether T is a floating - point type.
// Provides the member constant value which is equal to true, 
// if T is the type float, double, long double, including any cv - qualified variants.
// Otherwise, value is equal to false.
template 
<typename T>
struct _IsFloatingPointBase : FalseType {
};

template
<>
struct _IsFloatingPointBase<float> : TrueType {
};

template
<>
struct _IsFloatingPointBase<double> : TrueType {

};

template
<>
struct _IsFloatingPointBase<long double> : TrueType {
};

template
<typename T>
struct IsFloatingPoint : _IsFloatingPointBase<typename RemoveCv<T>::type> {
};

// Checks whether T is an array type. 
// Provides the member constant value which is equal to true, if T is an array type. 
// Otherwise, value is equal to false.
template
<typename T>
struct IsArray : FalseType {
};

// no need to specialization the cv version

template
<typename T>
struct IsArray<T[]> : TrueType {
};

template
<typename T, size_t N>
struct IsArray<T[N]> : TrueType {
};

// Checks whether T is an enumeration type.
// Provides the member constant value which is equal to true, if T is an enumeration type.
// Otherwise, value is equal to false.
template
<typename T>
struct IsEnum : FalseType {
};

template
<typename T>
struct IsEnum<enum> : TrueType {
};

