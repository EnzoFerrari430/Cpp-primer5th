#include <iostream>
using namespace std;
int main()
{
    char ch;
    int acnt = 0,ecnt = 0,icnt = 0,ocnt = 0,ucnt = 0,space_cnt = 0,t_cnt = 0,n_cnt = 0;
    while(cin>>noskipws>>ch)  //noskipws�ǲ���������ǰ�Ŀո�
    {
        switch(ch)
        {
        //case 'a'|'A':  case��ǩ���������ͳ������ʽ case 'a'��case 'A'���Թ���++acnt���
        case 'a':
        case 'A':
            ++acnt;
            break;
        case 'e':
        case 'E':
            ++ecnt;
            break;
        case 'i':
        case 'I':
            ++icnt;
            break;
        case 'o':
        case 'O':
            ++ocnt;
            break;
        case 'u':
        case 'U':
            ++ucnt;
            break;
        case ' ':
            ++space_cnt;
            break;
        case '\t':
            ++t_cnt;
            break;
        case '\n':
            ++n_cnt;
            break;
        }
    }
    cout<<acnt<<endl;
    cout<<ecnt<<endl;
    cout<<icnt<<endl;
    cout<<ocnt<<endl;
    cout<<ucnt<<endl;
    cout<<space_cnt<<endl;
    cout<<t_cnt<<endl;
    cout<<n_cnt<<endl;


    return 0;
}
