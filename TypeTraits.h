#pragma once
#include <type_traits>

using std::nullptr_t;

struct TrueType {
	constexpr static bool value = true;
};

struct FalseType {
	constexpr static bool value = false;
};

// Checks whether T is a void type. 
// Provides the member constant value that is equal to true, 
// if T is the type void, const void, volatile void, or const volatile void. 
// Otherwise, value is equal to false.
template
<typename Type>
struct IsVoid : FalseType{
};

template
<>
struct IsVoid<void> : TrueType{
};

// something about const void
// https://stackoverflow.com/questions/37881240/what-is-const-void/37881363
template
<>
struct IsVoid<const void> : TrueType {
};

template
<>
struct IsVoid<volatile void> : TrueType {
};

template
<>
struct IsVoid<const volatile void> : TrueType {
};

// Checks whether T is the type std::nullptr_t.
// Provides the member constant value that is equal to true, 
// if T is the type std::nullptr_t, const std::nullptr_t, volatile std::nullptr_t, or const volatile std::nullptr_t.
// Otherwise, value is equal to false.
template
<typename Type>
struct IsNullPointer : FalseType {
};

template
<typename Type>
struct IsNullPointer<nullptr_t> : TrueType {
};

template
<typename Type>
struct IsNullPointer<const nullptr_t> : TrueType {
};

template
<typename Type>
struct IsNullPointer<volatile nullptr_t> : TrueType {
};

template
<typename Type>
struct IsNullPointer<const volatile nullptr_t> : TrueType {
};