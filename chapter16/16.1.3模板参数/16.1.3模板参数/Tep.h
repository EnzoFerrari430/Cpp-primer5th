#pragma once
#ifndef TEP_H_
#define TEP_H_
#include <iostream>
typedef double A;
template <typename A, typename B> void f(A a, B b)
{
	A tmp = a;
	double b;
	std::cout << tmp << " " << b << std::endl;
}

#endif