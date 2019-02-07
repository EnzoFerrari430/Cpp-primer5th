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
	//����ҵ��˵���
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
	{
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}

void runQueries(std::ifstream &infile)
{
	//infile��һ��ifstream��ָ������Ҫ������ļ�
	TextQuery tq(infile);  //�����ļ�������ѯmap
						   //���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
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
	TextQuery tq(in);  //����Ҫ��ѯ���ı�
	//practice 15.39
	Query q = Query("fiery") & Query("bird") | Query("wind");  //Ҫ��ѯ������
	print(std::cout, q.eval(tq));
	system("pause");
    return 0;
}
