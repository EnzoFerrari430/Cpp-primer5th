#include <iostream>
#include "practice12.32.h"
using namespace std;

//std::ostream& print(std::ostream &out,const QueryResult& qr)
//{
//    out<<qr.word<<" occurs "<<qr.nos->size()<<(qr.nos->size() > 1? " times":" time")<<endl;
//    for(auto i: *qr.nos)
//    {
//        ConstStrBlobPtr p(qr.input,i);
//        out<<"\t(line "<<i+1<<" ) "<<p.deref()<<endl;
//    }
//    return out;
//}
//
//
//
//void runQueries(ifstream &infile)
//{
//    //infile��һ��ifstream��ָ������Ҫ������ļ�
//    TextQuery tq(infile);  //�����ļ���������ѯmap
//    //���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ�����ɲ�ѯ��ӡ���
//    while(true)
//    {
//        cout<<"enter word to look for, or q to quit: ";
//        string s;
//        if( !(cin>>s) || s == "q" )
//            break;
//        print(cout,tq.query(s))<<endl;
//    }
//}

int main()
{
    string file("E:\\CC++\\C++ primer\\chapter12\\12-27.txt");
    //cout<<file<<endl;
    ifstream in(file);
    runQueries(in);
    return 0;
}
