#pragma once
/*
在大型工程中，当2个或多个独立编译的源文件使用相同的模板，并提供了相同的模板参数时。
每个文件中都会有该模板的一个实例。这个实例化的类都是相同的。
这样会造成严重的额外开销

在C++11新标准中，我们可以通过显式实例化来避免这种开销
显式实例化的形式：
extern template declaration;  //实例化声明
template declaration;  //实例化定义

因为编译器在使用一个模板时自动对其实例化,因为extern声明必须出现在任何使用此实例化版本的代码之前


一个类模板的实例化定义会实例化该模板的所有成员，包括内联的成员函数.
当编译器遇到一个实例化定义时，编译器不知道程序使用了哪些成员函数，
因此，与处理类模板的普通实例化不同，编译器会实例化该类的所有成员。即使我们不使用某个成员
所以，当我们用显式实例化一个类模板类型时，该显式实例化出来的类，必须能用于模板的所有成员
*/