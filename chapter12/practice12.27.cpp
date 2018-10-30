#include "practice12.27.h"


TextQuery::TextQuery(ifstream &infile):input(new vector<string>)  //��̬�����ڴ�
{
    LineNo lineNo{0};

    for(string line; std::getline(infile,line ); ++lineNo)
    {
        input->push_back(line);
        std::istringstream line_stream(line);
        for(string text,word;line_stream >> text;word.clear())
        {
            //�ų������ŵĸ���
            //��text��ʹispunct��������Ԫ�ز鵽word��
            remove_copy_if(text.begin(),text.end(),std::back_inserter(word),::ispunct);
            //ʹ�����ñ�������ָ��ļ�����1
            //map�±����һ����������ȡ����������ֵ������ؼ��ֲ�����map�У���Ϊ������һ��Ԫ�ز����뵽map�У�����ֵ����ֵ��ʼ��
            auto &nos = result[word];
            if( !nos )
            {   //nosֵΪ0
                nos.reset(new std::set<LineNo>);
            }
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    //ʹ��staticֻ����һ���ڴ�
    static shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>);
    auto found = result.find(str);  //����һ��β���������ָ���һ���ؼ���Ϊstr��Ԫ�أ���str����Ԫ���з���β�������
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
    //infile��һ��ifstream��ָ������Ҫ������ļ�
    TextQuery tq(infile);  //�����ļ���������ѯmap
    //���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ�����ɲ�ѯ��ӡ���
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
