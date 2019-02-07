#include <iostream>
#include <Windows.h>
#include "Query_base.h"
using namespace std;
using namespace chapter10;
using namespace chapter15;


void runQueries(std::ifstream &infile)
{
	//infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);  //保存文件建立查询map
						   //与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while (true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
		{
			break;
		}
		print(std::cout, tq.query(s)) << std::endl;
	}
}
int main()
{
    //std::string sFile("D:\\CC++\\C++primer\\chapter15\\tial.txt");
    //std::ifstream in(sFile);
	std::ifstream in("D:\\CC++\\C++primer\\chapter15\\tial.txt");
	TextQuery tq(in);  //保存要查询的文本
	//practice 15.39
	Query q = Query("fiery") & Query("bird") | Query("wind");  //要查询的内容
	//print(std::cout, q.eval(tq));
	//Query q2 = ~Query("fiery");
	//print(std::cout, q2.eval(tq));
	system("pause");
    return 0;
}
