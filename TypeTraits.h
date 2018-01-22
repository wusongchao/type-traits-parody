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

template
<typename T>
struct RemoveCv {
	typedef RemoveVolatile<
		RemoveConst<T>::type
	>::type type;
};


// Checks whether T is a void type. 
// Provides the member constant value that is equal to true, 
// if T is the type void, const void, volatile void, or const volatile void. 
// Otherwise, value is equal to false.
template
<typename T>
struct IsVoid : IsSame<void, RemoveCv<T>::type>{
};

// something about const void
// https://stackoverflow.com/questions/37881240/what-is-const-void/37881363


// Checks whether T is the type std::nullptr_t.
// Provides the member constant value that is equal to true, 
// if T is the type std::nullptr_t, const std::nullptr_t, volatile std::nullptr_t, or const volatile std::nullptr_t.
// Otherwise, value is equal to false.
template
<typename T>
struct IsNullPointer : IsSame<nullptr_t, RemoveCv<T>::type> {
};

// Checks whether T is an integral type. 
// Provides the member constant value which is equal to true, 
// if T is the type bool, char, char16_t, char32_t, wchar_t, short, int, long, long long, 
// or any implementation-defined extended integer types, 
// including any signed, unsigned, and cv-qualified variants. 
// Otherwise, value is equal to false.