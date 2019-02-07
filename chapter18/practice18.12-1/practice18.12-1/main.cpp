#include <iostream>
#include <Windows.h>
#include "Query_base.h"
using namespace std;
using namespace chapter10;
using namespace chapter15;


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
	//print(std::cout, q.eval(tq));
	//Query q2 = ~Query("fiery");
	//print(std::cout, q2.eval(tq));
	system("pause");
    return 0;
}
