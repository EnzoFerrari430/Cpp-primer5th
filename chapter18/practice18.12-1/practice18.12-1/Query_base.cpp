#include "Query_base.h"

namespace chapter15
{
	//������������ѯ���set�Ĳ���
	QueryResult OrQuery::eval(const TextQuery& text)const
	{
		//ͨ��Query��Աlhs��rhs���е������
		//����eval����ÿ�������QueryResult
		auto right = rhs.eval(text);  //��ѯ�ұߵ�ResultQuery
		auto left = lhs.eval(text);  //��ѯ��ߵ�ResultQuery

									 //����������кſ��������set��
		auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
		//���Ҳ������뵽ret_lines��,ret_lines��һ��ָ��set������ָ��,��map��setֻ���벻�ڵ�ǰ�����е�Ԫ��
		ret_lines->insert(right.begin(), right.end());
		return QueryResult(rep(), ret_lines, left.get_file());
	}

	//������������ѯ���set�Ľ���
	QueryResult AndQuery::eval(const TextQuery& text)const
	{
		auto right = rhs.eval(text);
		auto left = lhs.eval(text);

		auto ret_lines = std::make_shared<std::set<line_no>>();

		//�����������е�����Ԫ�أ��������ǵ��������С��������ж�������Ԫ�������������ֻ����һ�Ρ�������б�����ret_lines��
		std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
		return QueryResult(rep(), ret_lines, left.get_file());
	}

	//�����������Ľ��set�в����ڵ���
	QueryResult NotQuery::eval(const TextQuery& text)const
	{
		auto result = query.eval(text);  //��ѯ�Ľ��ResultQuery,result�м�¼�˸õ��ʳ��ֵ��к�

										 //��ʼʱ�����Ϊ��
		auto ret_lines = std::make_shared<std::set<line_no>>();
		//���Ǳ��������������ֵ��������н��е���
		auto beg = result.begin(), end = result.end();
		//���������ļ���ÿһ�У�������в���result���У�������ӵ�ret_lines
		auto sz = result.get_file()->size();
		for (size_t n = 0; n != sz; ++n)
		{
			//�����õ������õ��õ�����ָ�������ֵ
			//beg == end��ʾresult�е������Ѿ�û���ˣ�ʣ�µ��к�n�����Լӵ�ret_lines�У����begû��ĩβ����beg��ʾ���кŲ�����nҲ���Լӵ�ret_lines��
			if (beg == end || *beg != n)
			{
				ret_lines->insert(n);
			}
			//�����ǰbegû��ĩβ����beg��ʾ���кŵ���n������n������beg����
			else if (beg != end)
			{
				++beg;
			}
		}
		return QueryResult(rep(), ret_lines, result.get_file());
	}

	std::ostream& operator<<(std::ostream &os, const Query &query)
	{
		//Query::repͨ������Query_baseָ���rep()�����������
		return os << query.rep();
	}
}