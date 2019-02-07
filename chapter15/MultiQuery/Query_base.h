#ifndef QUERY_BASE_H_INCLUDED
#define QUERY_BASE_H_INCLUDED

#include "12-3-2TextQuery.h"
#include <iterator>

//һ��������࣬����Ĳ�ѯ���ʹ������������г�Ա����private��
class Query_base
{
    friend class Query;
protected:
    //using line_no = line_no;  //����eval����
    virtual ~Query_base() = default;

private:
    //eval���������뵱ǰQueryƥ���QueryResult
    virtual QueryResult eval(const TextQuery&)const = 0;  //���麯��
    //rep��ʾ��ѯ��һ��string
    virtual std::string rep() const = 0;

};

class WordQuery : public Query_base
{
    friend class Query;  //Queryʹ��WordQuery���캯��
	WordQuery(const std::string &s) :query_word(s) { std::cout << "construction in WordQuery" << std::endl; }
    //WordQueryҪ�������м̳ж����Ĵ��麯������ȻWordQuery�Լ�Ҳ���˴��麯��
    virtual QueryResult eval(const TextQuery& t)const override{return t.query(query_word);}
	virtual std::string rep()const override { return query_word; std::cout << "rep in WordQuery" << std::endl; }


    std::string query_word;  //Ҫ���ҵĵ���
};

//���� һ������Query_base�̳���ϵ�Ľӿ���
class Query
{
    //��Щ�������Ҫ���ʽ���shared_ptr�Ĺ��캯�������ú�����˽�е�
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    friend std::ostream& operator<<(std::ostream &os,const Query &query);
public:
    Query(const std::string &);  //����һ���µ�WordQuery
    //�ӿں��������ö�Ӧ��Query_base����
    QueryResult eval(const TextQuery& t)const{return q->eval(t);}
	std::string rep() const { std::cout << "rep in Query" << std::endl; return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) :q(query) { std::cout << "construction2 in Query" << std::endl; }
    std::shared_ptr<Query_base> q;
};


inline Query::Query(const std::string& s) :q(new WordQuery(s)) { std::cout << "construction in Query" << std::endl; }


class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query& q):query(q){}
    //������ࣺҪ���¶���Query_base�Ĵ��麯��
    virtual QueryResult eval(const TextQuery&)const override;
    virtual std::string rep()const {return "~(" + query.rep() + ")";}
    Query query;
};

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}


//�������BinaryQuery��
class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :lhs(l), rhs(r), opSym(s) { std::cout << "construction in BinaryQuery" << std::endl; }
    //������� BinaryQuery������eval
	virtual std::string rep()const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; std::cout << "rep in BinaryQuery" << std::endl; }
    Query lhs,rhs;  //�����Ҳ��������
    std::string opSym;  //�����������
};


class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&,const Query&);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") { std::cout << "constrction in AndQuery" << std::endl; }
    //������࣬AndQuery�̳���rep���Ҷ������������麯��
    virtual QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query& lhs,const Query& rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));  //ͨ�������������ʽ������һ��Query
}

class OrQuery:public BinaryQuery
{
    friend Query operator|(const Query&,const Query&);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") { std::cout << "constrcution in OrQuery" << std::endl; }
    //������࣬OrQuery�̳���rep���Ҷ������������麯��
    virtual QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query& lhs,const Query& rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}


#endif // QUERY_BASE_H_INCLUDED