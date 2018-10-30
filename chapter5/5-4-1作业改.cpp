#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string My_string, before_string, max_repeatstring;
	int repeat_number = 0, flag = 0;
	while (cin >> My_string)
	{
		if (My_string == before_string)
		{
			++repeat_number;
		}
		else
		{
			repeat_number = 1;
			before_string = My_string;
		}

		if (flag < repeat_number)
		{
			flag = repeat_number;
			max_repeatstring = before_string;
		}//设置flag,max_repeatstring用来保存当前比较完字符串后的最大重复次数和对应字符串
	}
	if (flag == 1)
	{
		cout<<"没有重复的字符串出现"<<endl;
	}
	else
	{
		cout<<"单词"<<max_repeatstring<<"出现了"<<flag<<"次"<<endl;
	}
	return 0;
}
