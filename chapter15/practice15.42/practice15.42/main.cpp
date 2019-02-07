#include <iostream>
#include <Windows.h>
#include "Query_base.h"
using namespace std;

std::string make_plural(int num, const std::string &s, const std::string &s2)
{
	return (num > 1 ? s + s2 : s);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	//如果找到了单词
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
	{
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}

//practice15.42 C版本
std::ostream &print(std::ostream &os, const QueryResult &qr,int begin,int end)
{
	std::vector<int> vi;	
	for (auto num : *qr.lines)
	{
		if (num >= begin && num <= end)
		{
			vi.push_back(num);
			//os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
		}
	}
	int n = vi.size();
	//如果找到了单词
	os << qr.sought << " occurs " << n << " " << make_plural(n, "time", "s") << " in range from " << begin << " to " << end << std::endl;
	for (int i = 0; i < n; ++i)
	{
		os << "\t(line " << vi[i] + 1 << ") " << *(qr.file->begin() + vi[i]) << std::endl;
	}
	return os;
}


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
	print(std::cout, q.eval(tq));
	print(std::cout, q.eval(tq),3,5);
	//Query q2 = ~Query("fiery");
	//print(std::cout, q2.eval(tq));
	system("pause");
    return 0;
}
