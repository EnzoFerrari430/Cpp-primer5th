#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ifstream fr("E:\\Enzo.txt");  //����ifstream����һ���ļ�
    vector<string> sval;
    string str,word;
    while(getline(fr,str))
    {
        sval.push_back(str);
    }

    for(vector<string>::iterator vi = sval.begin();vi != sval.end() ;++vi)
    {
        istringstream record(*vi);  //�󶨵���ȡ����
        while(record >> word)  //���ַ����뵽word��
            cout<<word<<endl;
    }

    return 0;
}
