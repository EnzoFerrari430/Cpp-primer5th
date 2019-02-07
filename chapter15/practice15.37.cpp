/*
    如果派生类使用shared_ptr<Query_base>类型,而不是Query

    在查找单个单词的时候，就必须创建WordQuery类而不是Query对象

    复合查询的时候，要使用Query_base指针，从而大大增加了难度。

    需要逐个完成运算，将结果赋予Query_base指针。

    资源管理方面也需要重新设计
*/

class WordQuery : public Query_base
{
    friend class Query;  //Query使用WordQuery构造函数
	WordQuery(const std::string &s) :wq( new string(s) ) { std::cout << "construction in WordQuery" << std::endl; }
    //WordQuery要定义所有继承而来的纯虚函数，不然WordQuery自己也成了纯虚函数
    //virtual QueryResult eval(const TextQuery& t)const override{return t.query(query_word);}
	virtual std::string rep()const override { return query_word; std::cout << "rep in WordQuery" << std::endl; }


    std::string query_word;  //要查找的单词
    std::shared_ptr<Query_base> wq;
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
    //QueryResult eval(const TextQuery& t)const{return q->eval(t);}
	std::string rep() const { return q->rep(); std::cout << "rep in Query" << std::endl; }
private:
	Query(std::shared_ptr<Query_base> query) :q(query) { std::cout << "construction2 in Query" << std::endl; }
    std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream &os,const Query &query)
{
    //Query::rep通过它的Query_base指针对rep()进行了虚调用
    return os<<query.rep();
}
inline Query::Query(const std::string& s) :q(new WordQuery(s)) { std::cout << "construction in Query" << std::endl; }
