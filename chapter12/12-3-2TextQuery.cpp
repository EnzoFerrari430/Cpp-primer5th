#include "12-3-2TextQuery.h"

TextQuery::TextQuery(std::ifstream &is)
    :file(new std::vector<std::string>)
{
    std::string line;
    while( getline(is,line) )
    {
        file->push_back(line);
        int n = file->size() - 1;  //��ǰ�к�
        std::istringstream word(line);  //�ֽ��ı�
        std::string str;
        while(word>>str)
        {
            auto &lines = wm[str];  //���ص���һ������ָ��
            if( !lines )  //����ǿ�
            {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);  //����ǰ�к�
        }
        //word>>str;

    }
}

QueryResult TextQuery::query(const std::string &s) const
{
    //���δ�ҵ�sought�����Ǿͷ���һ��ָ���set��ָ��
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    //ʹ��find�������±�����������ҵ��ʣ����⽫���ʼӵ�wm��
    auto loc = wm.find(s);

    //δ�ҵ�
    if(loc == wm.end())
    {
        return QueryResult(s,nodata,file);
    }
    else
    {
        return QueryResult(s,loc->second,file);
    }
}

std::string make_plural(int num,const std::string &s,const std::string &s2)
{
    return (num > 1? s+s2 : s);
}

std::ostream &print(std::ostream &os,const QueryResult &qr)
{
    //����ҵ��˵���
    os<<qr.sought<< " occurs "<<qr.lines->size() << " "<<make_plural(qr.lines->size(),"time","s")<<std::endl;
    for(auto num : *qr.lines )
    {
        os<<"\t(line "<<num+1<<") "<< *(qr.file->begin() + num)<<std::endl;
    }
    return os;
}

void runQueries(std::ifstream &infile)
{
    //infile��һ��ifstream��ָ������Ҫ������ļ�
    TextQuery tq(infile);  //�����ļ�������ѯmap
    //���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
    while(true)
    {
        std::cout<< "enter word to look for, or q to quit: ";
        std::string s;
        if( !(std::cin>>s ) || s == "q" )
        {
            break;
        }
        print(std::cout,tq.query(s)) <<std::endl;
    }
}


int main()
{
    std::string sFile("D:\\CC++\\C++ primer\\chapter12\\12-27.txt");
    std::ifstream in(sFile);
    //TextQuery Tq(in);
    //print(std::cout,Tq.query("you"));
    runQueries(in);

    return 0;
}

/*
    12.31   vector�ᱣ���ظ����к�
*/
