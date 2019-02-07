/*
    a)  Query q = Query("fiery") & Query("bird") | Query("wind");
        1.Query("wind"):  WordQuery(const std::string &s)    Query(const std::string &)  //Query�Ĺ��캯�����ȵ���WordQuery�Ĺ��캯��
        2.Query("bird"):  WordQuery(const std::string &s)    Query(const std::string &)
        3.Query("fiery"): WordQuery(const std::string &s)    Query(const std::string &)
        4.Query("fiery") & Query("bird"):  AndQuery(const Query &left,const Query &right)
        5.Query("fiery") & Query("bird"):  BinaryQuery(const Query &l,const Query &r,std::string s)
        6.Query("fiery") & Query("bird"):  Query(std::shared_ptr<Query_base> query)
        7.Query("fiery") & Query("bird") | Query("wind"):OrQuery(const Query &left,const Query &right)
        8.Query("fiery") & Query("bird") | Query("wind"):BinaryQuery(const Query &l,const Query &r,std::string s)
        9.Query("fiery") & Query("bird") | Query("wind"):Query(std::shared_ptr<Query_base> query)

    b) cout<<q
        1.�����Լ��ĳ�Ա����Query.rep()const{return q->rep();}
        2.q��һ������ָ�룬��̬�󶨵�������OrQuery������.���������еĻ����ԱΪ  AndQuery(Query("fiery"),Query("bird")),Query("wind"),"|"
        3.���û����rep�������������  "(" + lhs.rep() + " " + "|" + " "+ rhs.rep() + ")",����lhs��AndQuery(Query("fiery"),Query("bird"))��rhsΪQuery("wind"))��opSymΪ��|��
        4.������ߵ�AndQuery��rep��������� "(" + "(" + lhs.rep() + " " + "&" + " "+ rhs.rep() + ")" + " " + "|" + " "+ rhs.rep() + ")"������lhsΪQuery("fiery")  ��һ��rhsΪQuery("bird")  �ڶ���rhsΪQuery("wind")
        5.������ߵ�Query��rep��������� "(" + "(" + "fiery" + " " + "&" + " "+ rhs.rep() + ")" + " " + "|" + " "+ rhs.rep() + ")"������lhsΪQuery("fiery")  ��һ��rhsΪQuery("bird")  �ڶ���rhsΪQuery("wind")
        6.���õ�һ����rhs��rep��������� "(" + "(" + "fiery" + " " + "&" + " "+ "bird" + ")" + " " + "|" + " "+ rhs.rep() + ")"������lhsΪQuery("fiery")  ��һ��rhsΪQuery("bird")  �ڶ���rhsΪQuery("wind")
        7.������ߵ�Query��rep��������� "(" + "(" + "fiery" + " " + "&" + " "+ "bird" + ")" + " " + "|" + " "+ "wind" + ")"������lhsΪQuery("fiery")  ��һ��rhsΪQuery("bird")  �ڶ���rhsΪQuery("wind")
        8.����һ��  ((fiery & bird) | wind)

    c) q.eval();
        1.�����Լ��ĳ�Ա����QueryResult eval(const TextQuery& t)const{return q->eval(t);}
        2.��ʱq��������Query_base��������OrQuery�����������OrQuery��eval����
        3.�ڵ���AndQuery��eval������WordQuery��eval����
        4.AndQuery��eval�ٵ���WordQuery��eval����

*/
