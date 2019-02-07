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



/*
    12.31   vector�ᱣ���ظ����к�
*/
