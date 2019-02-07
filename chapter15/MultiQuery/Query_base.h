#ifndef QUERY_BASE_H_INCLUDED
#define QUERY_BASE_H_INCLUDED

#include "12-3-2TextQuery.h"
#include <iterator>

//一个抽象基类，具体的查询类型从中派生，所有成员都是private的
class Query_base
{
    friend class Query;
protected:
    //using line_no = line_no;  //用于eval函数
    virtual ~Query_base() = default;

private:
    //eval函数返回与当前Query匹配的QueryResult
    virtual QueryResult eval(const TextQuery&)const = 0;  //纯虚函数
    //rep表示查询的一个string
    virtual std::string rep() const = 0;

};

class WordQuery : public Query_base
{
    friend class Query;  //Query使用WordQuery构造函数
	WordQuery(const std::string &s) :query_word(s) { std::cout << "construction in WordQuery" << std::endl; }
    //WordQuery要定义所有继承而来的纯虚函数，不然WordQuery自己也成了纯虚函数
    virtual QueryResult eval(const TextQuery& t)const override{return t.query(query_word);}
	virtual std::string rep()const override { return query_word; std::cout << "rep in WordQuery" << std::endl; }


    std::string query_word;  //要查找的单词
};

//这是 一个管理Query_base继承体系的接口类
class Query
{
    //这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    friend std::ostream& operator<<(std::ostream &os,const Query &query);
public:
    Query(const std::string &);  //构造一个新的WordQuery
    //接口函数，调用对应的Query_base操作
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
    //具体的类：要重新定义Query_base的纯虚函数
    virtual QueryResult eval(const TextQuery&)const override;
    virtual std::string rep()const {return "~(" + query.rep() + ")";}
    Query query;
};

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}


//抽象基类BinaryQuery类
class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :lhs(l), rhs(r), opSym(s) { std::cout << "construction in BinaryQuery" << std::endl; }
    //抽象基类 BinaryQuery不定义eval
	virtual std::string rep()const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; std::cout << "rep in BinaryQuery" << std::endl; }
    Query lhs,rhs;  //左侧和右侧运算对象
    std::string opSym;  //运算符的名字
};


class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&,const Query&);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") { std::cout << "constrction in AndQuery" << std::endl; }
    //具体的类，AndQuery继承了rep并且定义了其他纯虚函数
    virtual QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query& lhs,const Query& rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));  //通过返回这个表达式构造了一个Query
}

class OrQuery:public BinaryQuery
{
    friend Query operator|(const Query&,const Query&);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") { std::cout << "constrcution in OrQuery" << std::endl; }
    //具体的类，OrQuery继承了rep并且定义了其他纯虚函数
    virtual QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query& lhs,const Query& rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}


#endif // QUERY_BASE_H_INCLUDED
