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
		}//����flag,max_repeatstring�������浱ǰ�Ƚ����ַ����������ظ������Ͷ�Ӧ�ַ���
	}
	if (flag == 1)
	{
		cout<<"û���ظ����ַ�������"<<endl;
	}
	else
	{
		cout<<"����"<<max_repeatstring<<"������"<<flag<<"��"<<endl;
	}
	return 0;
}
