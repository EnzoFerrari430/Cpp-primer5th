#include "practice12.27.h"
#include <Windows.h>


void runQueries(ifstream &infile)
{
	//infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);  //保存文件并建立查询map
						   //与用户交互，提示用户输入要查询的单词，并完成查询打印结果
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