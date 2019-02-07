#include "12-3-2TextQuery.h"

namespace chapter10
{
	TextQuery::TextQuery(std::ifstream &is)
		:file(new std::vector<std::string>)
	{
		std::string line;
		while (getline(is, line))
		{
			file->push_back(line);
			int n = file->size() - 1;  //当前行号
			std::istringstream word(line);  //分解文本
			std::string str;
			while (word >> str)
			{
				auto &lines = wm[str];  //返回的是一个智能指针
				if (!lines)  //如果是空
				{
					lines.reset(new std::set<line_no>);
				}
				lines->insert(n);  //将当前行号
			}
			//word>>str;

		}
	}

	QueryResult TextQuery::query(const std::string &s) const
	{
		//如果未找到sought，我们就返回一个指向此set的指针
		static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
		//使用find而不是下标运算符来查找单词，避免将单词加到wm中
		auto loc = wm.find(s);

		//未找到
		if (loc == wm.end())
		{
			return QueryResult(s, nodata, file);
		}
		else
		{
			return QueryResult(s, loc->second, file);
		}
	}

	std::ostream &print(std::ostream &os, const QueryResult &qr)
	{
		//如果找到了单词
		os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
		for (auto num : *qr.lines)
		{
			os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
		}
		return os;
	}

	std::string make_plural(int num, const std::string &s, const std::string &s2)
	{
		return (num > 1 ? s + s2 : s);
	}
}

/*
    12.31   vector会保存重复的行号
*/
