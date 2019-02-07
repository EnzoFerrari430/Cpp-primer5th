#include "Query_base.h"

namespace chapter15
{
	//返回运算对象查询结果set的并集
	QueryResult OrQuery::eval(const TextQuery& text)const
	{
		//通过Query成员lhs和rhs进行的虚调用
		//调用eval返回每个对象的QueryResult
		auto right = rhs.eval(text);  //查询右边的ResultQuery
		auto left = lhs.eval(text);  //查询左边的ResultQuery

									 //将左侧对象的行号拷贝到结果set中
		auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
		//将右侧对象插入到ret_lines中,ret_lines是一个指向set的智能指针,对map和set只插入不在当前容器中的元素
		ret_lines->insert(right.begin(), right.end());
		return QueryResult(rep(), ret_lines, left.get_file());
	}

	//返回运算对象查询结果set的交集
	QueryResult AndQuery::eval(const TextQuery& text)const
	{
		auto right = rhs.eval(text);
		auto left = lhs.eval(text);

		auto ret_lines = std::make_shared<std::set<line_no>>();

		//对两个序列中的所有元素，创建它们的有序序列。两个序列都包含的元素在输出序列中只出现一次。输出序列保存在ret_lines中
		std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
		return QueryResult(rep(), ret_lines, left.get_file());
	}

	//返回运算对象的结果set中不存在的行
	QueryResult NotQuery::eval(const TextQuery& text)const
	{
		auto result = query.eval(text);  //查询的结果ResultQuery,result中记录了该单词出现的行号

										 //开始时，结果为空
		auto ret_lines = std::make_shared<std::set<line_no>>();
		//我们必须在运算对象出现的所有行中进行迭代
		auto beg = result.begin(), end = result.end();
		//对于输入文件的每一行，如果该行不在result当中，则将其添加到ret_lines
		auto sz = result.get_file()->size();
		for (size_t n = 0; n != sz; ++n)
		{
			//解引用迭代器得到该迭代器指向的数据值
			//beg == end表示result中的数据已经没有了，剩下的行号n都可以加到ret_lines中，如果beg没到末尾，则beg表示的行号不等于n也可以加到ret_lines中
			if (beg == end || *beg != n)
			{
				ret_lines->insert(n);
			}
			//如果当前beg没到末尾而且beg表示的行号等于n则跳过n，并且beg自增
			else if (beg != end)
			{
				++beg;
			}
		}
		return QueryResult(rep(), ret_lines, result.get_file());
	}

	std::ostream& operator<<(std::ostream &os, const Query &query)
	{
		//Query::rep通过它的Query_base指针对rep()进行了虚调用
		return os << query.rep();
	}
}