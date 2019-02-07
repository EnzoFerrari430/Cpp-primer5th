#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_
#include <string>
#include <iostream>
/*
非类型模板参数表示一个值而非一个类型
*/
using pos = std::string::size_type;

template <unsigned H,unsigned W>
class Screen
{
public:
	Screen() = default;
	Screen(char c):contents(H*W,c){}
	char get()const
	{
		return contents[cursor];  //返回光标出的字符
	}

	Screen &move(pos r, pos c);

	friend std::ostream& operator<<(std::ostream &os, const Screen<H, W>& c)
	{
		unsigned int i, j;
		for (i = 0; i < c.height; ++i)
		{
			os << c.contents.substr(0, W);
		}
		return os;
	}

	friend std::istream& operator >> (std::istream &is, Screen& c)
	{
		char a;
		is >> a;
		std::string temp(H*W, a);
		c.contents = temp;
		return is;
	}

private:
	pos cursor = 0;
	pos height = H;
	pos width = W;
	std::string contents;
};

template <unsigned H,unsigned W>
inline Screen<H, W>& Screen<H, W>::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
}

#endif // !SCREEN_H_
