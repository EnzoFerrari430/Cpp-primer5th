#include "practice12.27.h"
#include <Windows.h>


void runQueries(ifstream &infile)
{
	//infile��һ��ifstream��ָ������Ҫ������ļ�
	TextQuery tq(infile);  //�����ļ���������ѯmap
						   //���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ�����ɲ�ѯ��ӡ���
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	string file("D:\\CC++\\C++primer\\chapter12\\12-27.txt");
	//cout<<file<<endl;
	ifstream in(file);
	runQueries(in);
	system("pause");
	return 0;
}