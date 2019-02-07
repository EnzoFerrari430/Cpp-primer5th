#pragma once
#include <memory>
#include <vector>
/*
对于类模板，我们也可以为其定义成员模板。
在此情况下，类和成员各自有自己的独立的模板参数
*/
template <typename T>
class Blob
{
public:
	//此构造函数有自己的模板参数类型It，作为它的两个函数参数的类型
	template <typename It> Blob(It b, It e);
private:
	std::shared_ptr<std::vector<T>> data;
};

//类模板的函数模板在类外定义时，必须同时为类模板和成员模板提供模板参数列表
//类模板参数在前，后跟自己的模板列表
template <typename T>
template <typename It>
Blob<T>::Blob(It b,It e):data(std::make_shared<std::vector<T>>(b,e)){}