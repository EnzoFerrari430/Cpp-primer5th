#include <iostream>
#include <string>
#include <vector>
using namespace std;

//9.41
int main()
{
    vector<char> vc{'E','n','z','o'};
    string s1(vc.begin(),vc.end());
    cout<<s1<<endl;

    return 0;
}

//9.42 string��vectorһ������reserveԤ����һƬ�ڴ�ռ�,�����Ͳ���Ҫת���ڴ�����
