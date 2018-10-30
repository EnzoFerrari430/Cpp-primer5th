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
//    //infile是一个ifstream，指向我们要处理的文件
//    TextQuery tq(infile);  //保存文件并建立查询map
//    //与用户交互，提示用户输入要查询的单词，并完成查询打印结果
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
