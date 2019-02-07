#include "practice12.27.h"


TextQuery::TextQuery(ifstream &infile):input(new vector<string>(),DebugDelete()),result( new map<string,set<LineNo>>(),DebugDelete() )  //动态申请内存
{
    //LineNo lineNo{0};

    //for(string line; std::getline(infile,line ); ++lineNo)
    //{
    //    input->push_back(line);
    //    std::istringstream line_stream(line);
    //    for(string text,word;line_stream >> text;word.clear())
    //    {
    //        //排除标点符号的干扰
    //        //将text中使ispunct不成立的元素查到word中
    //        remove_copy_if(text.begin(),text.end(),std::back_inserter(word),ispunct);
    //        //使用引用避免智能指针的计数加1
    //        //map下标接受一个索引，获取与此相关联的值。如果关键字并不在map中，会为它创建一个元素并插入到map中，关联值进行值初始化
    //        auto &nos = (*result)[word];
    //        if( !nos )
    //        {   //nos值为0
    //            nos.reset(new std::set<LineNo>);
    //        }
    //        nos->insert(lineNo);
    //    }
    //}
	string line;
	while (getline(infile, line))
	{
		input->push_back(line);  //改写构造函数，只负责保存
	}
}

QueryResult TextQuery::query(const string &str) const
{
    ////使用static只申请一次内存
    //static shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>);
    //auto found = result.find(str);  //返回一个尾后迭代器，指向第一个关键字为str的元素，若str不在元素中返回尾后迭代器
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