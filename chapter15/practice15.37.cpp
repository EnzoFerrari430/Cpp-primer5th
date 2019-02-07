/*
    ���������ʹ��shared_ptr<Query_base>����,������Query

    �ڲ��ҵ������ʵ�ʱ�򣬾ͱ��봴��WordQuery�������Query����

    ���ϲ�ѯ��ʱ��Ҫʹ��Query_baseָ�룬�Ӷ�����������Ѷȡ�

    ��Ҫ���������㣬���������Query_baseָ�롣

    ��Դ������Ҳ��Ҫ�������
*/

class WordQuery : public Query_base
{
    friend class Query;  //Queryʹ��WordQuery���캯��
	WordQuery(const std::string &s) :wq( new string(s) ) { std::cout << "construction in WordQuery" << std::endl; }
    //WordQueryҪ�������м̳ж����Ĵ��麯������ȻWordQuery�Լ�Ҳ���˴��麯��
    //virtual QueryResult eval(const TextQuery& t)const override{return t.query(query_word);}
	virtual std::string rep()const override { return query_word; std::cout << "rep in WordQuery" << std::endl; }


    std::string query_word;  //Ҫ���ҵĵ���
    std::shared_ptr<Query_base> wq;
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
    //QueryResult eval(const TextQuery& t)const{return q->eval(t);}
	std::string rep() const { return q->rep(); std::cout << "rep in Query" << std::endl; }
private:
	Query(std::shared_ptr<Query_base> query) :q(query) { std::cout << "construction2 in Query" << std::endl; }
    std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream &os,const Query &query)
{
    //Query::repͨ������Query_baseָ���rep()�����������
    return os<<query.rep();
}
inline Query::Query(const std::string& s) :q(new WordQuery(s)) { std::cout << "construction in Query" << std::endl; }
