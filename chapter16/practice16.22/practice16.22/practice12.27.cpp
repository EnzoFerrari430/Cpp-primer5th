#include "practice12.27.h"


TextQuery::TextQuery(ifstream &infile):input(new vector<string>(),DebugDelete()),result( new map<string,set<LineNo>>(),DebugDelete() )  //��̬�����ڴ�
{
    //LineNo lineNo{0};

    //for(string line; std::getline(infile,line ); ++lineNo)
    //{
    //    input->push_back(line);
    //    std::istringstream line_stream(line);
    //    for(string text,word;line_stream >> text;word.clear())
    //    {
    //        //�ų������ŵĸ���
    //        //��text��ʹispunct��������Ԫ�ز鵽word��
    //        remove_copy_if(text.begin(),text.end(),std::back_inserter(word),ispunct);
    //        //ʹ�����ñ�������ָ��ļ�����1
    //        //map�±����һ����������ȡ����������ֵ������ؼ��ֲ�����map�У���Ϊ������һ��Ԫ�ز����뵽map�У�����ֵ����ֵ��ʼ��
    //        auto &nos = (*result)[word];
    //        if( !nos )
    //        {   //nosֵΪ0
    //            nos.reset(new std::set<LineNo>);
    //        }
    //        nos->insert(lineNo);
    //    }
    //}
	string line;
	while (getline(infile, line))
	{
		input->push_back(line);  //��д���캯����ֻ���𱣴�
	}
}

QueryResult TextQuery::query(const string &str) const
{
    ////ʹ��staticֻ����һ���ڴ�
    //static shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>);
    //auto found = result.find(str);  //����һ��β���������ָ���һ���ؼ���Ϊstr��Ԫ�أ���str����Ԫ���з���β�������
    //if(found == result.end())
    //{
    //    return QueryResult(str,nodata,input);
    //}
    //return QueryResult(str,found->second,input);
	int count = 0;
	for (size_t i = 0; i != input->size(); ++i)
	{
		stringstream lineStream((*input)[i]);
		string word;
		while (lineStream >> word)
		{
			if (!word.compare(str))
			{
				++count;
				(*result)[word].insert(i);
			}
		}
	}

	return QueryResult(count, str, input, result);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.counter << (qr.counter > 1 ? " times" : " time") << endl;
	for (auto i : (*qr.nos)[qr.word])
	{
		out << "\t(line " << i + 1 << " ) " << qr.input->at(i) << endl;
	}
	return out;
}