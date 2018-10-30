#include "practice12.27.h"


TextQuery::TextQuery(ifstream &infile):input(new vector<string>)  //动态申请内存
{
    LineNo lineNo{0};

    for(string line; std::getline(infile,line ); ++lineNo)
    {
        input->push_back(line);
        std::istringstream line_stream(line);
        for(string text,word;line_stream >> text;word.clear())
        {
            //排除标点符号的干扰
            //将text中使ispunct不成立的元素查到word中
            remove_copy_if(text.begin(),text.end(),std::back_inserter(word),::ispunct);
            //使用引用避免智能指针的计数加1
            //map下标接受一个索引，获取与此相关联的值。如果关键字并不在map中，会为它创建一个元素并插入到map中，关联值进行值初始化
            auto &nos = result[word];
            if( !nos )
            {   //nos值为0
                nos.reset(new std::set<LineNo>);
            }
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    //使用static只申请一次内存
    static shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>);
    auto found = result.find(str);  //返回一个尾后迭代器，指向第一个关键字为str的元素，若str不在元素中返回尾后迭代器
    if(found == result.end())
    {
        return QueryResult(str,nodata,input);
    }
    return QueryResult(str,found->second,input);
}

std::ostream& print(std::ostream &out,const QueryResult& qr)
{
    out<<qr.word<<" occurs "<<qr.nos->size()<<(qr.nos->size() > 1? " times":" time")<<endl;
    for(auto i: *qr.nos)
    {
        out<<"\t(line "<<i+1<<" ) "<<qr.input->at(i)<<endl;
    }
    return out;
}



void runQueries(ifstream &infile)
{
    //infile是一个ifstream，指向我们要处理的文件
    TextQuery tq(infile);  //保存文件并建立查询map
    //与用户交互，提示用户输入要查询的单词，并完成查询打印结果
    while(true)
    {
        cout<<"enter word to look for, or q to quit: ";
        string s;
        if( !(cin>>s) || s == "q" )
            break;
        print(cout,tq.query(s))<<endl;
    }
}

int main()
{
    string file("D:\\CC++\\C++ primer\\chapter12\\12-27.txt");
    //cout<<file<<endl;
    ifstream in(file);
    runQueries(in);
    return 0;
}
