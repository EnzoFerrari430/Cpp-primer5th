/*
    a)  Query q = Query("fiery") & Query("bird") | Query("wind");
        1.Query("wind"):  WordQuery(const std::string &s)    Query(const std::string &)  //Query的构造函数会先调用WordQuery的构造函数
        2.Query("bird"):  WordQuery(const std::string &s)    Query(const std::string &)
        3.Query("fiery"): WordQuery(const std::string &s)    Query(const std::string &)
        4.Query("fiery") & Query("bird"):  AndQuery(const Query &left,const Query &right)
        5.Query("fiery") & Query("bird"):  BinaryQuery(const Query &l,const Query &r,std::string s)
        6.Query("fiery") & Query("bird"):  Query(std::shared_ptr<Query_base> query)
        7.Query("fiery") & Query("bird") | Query("wind"):OrQuery(const Query &left,const Query &right)
        8.Query("fiery") & Query("bird") | Query("wind"):BinaryQuery(const Query &l,const Query &r,std::string s)
        9.Query("fiery") & Query("bird") | Query("wind"):Query(std::shared_ptr<Query_base> query)

    b) cout<<q
        1.调用自己的成员函数Query.rep()const{return q->rep();}
        2.q是一个智能指针，动态绑定到派生类OrQuery对象上.该派生类中的基类成员为  AndQuery(Query("fiery"),Query("bird")),Query("wind"),"|"
        3.调用基类的rep函数输出成这样  "(" + lhs.rep() + " " + "|" + " "+ rhs.rep() + ")",其中lhs是AndQuery(Query("fiery"),Query("bird"))，rhs为Query("wind"))，opSym为“|”
        4.调用左边的AndQuery的rep输出成这样 "(" + "(" + lhs.rep() + " " + "&" + " "+ rhs.rep() + ")" + " " + "|" + " "+ rhs.rep() + ")"，其中lhs为Query("fiery")  第一个rhs为Query("bird")  第二个rhs为Query("wind")
        5.调用左边的Query的rep输出成这样 "(" + "(" + "fiery" + " " + "&" + " "+ rhs.rep() + ")" + " " + "|" + " "+ rhs.rep() + ")"，其中lhs为Query("fiery")  第一个rhs为Query("bird")  第二个rhs为Query("wind")
        6.调用第一个的rhs的rep输出成这样 "(" + "(" + "fiery" + " " + "&" + " "+ "bird" + ")" + " " + "|" + " "+ rhs.rep() + ")"，其中lhs为Query("fiery")  第一个rhs为Query("bird")  第二个rhs为Query("wind")
        7.调用左边的Query的rep输出成这样 "(" + "(" + "fiery" + " " + "&" + " "+ "bird" + ")" + " " + "|" + " "+ "wind" + ")"，其中lhs为Query("fiery")  第一个rhs为Query("bird")  第二个rhs为Query("wind")
        8.整合一下  ((fiery & bird) | wind)

    c) q.eval();
        1.调用自己的成员函数QueryResult eval(const TextQuery& t)const{return q->eval(t);}
        2.此时q的类型是Query_base的派生类OrQuery，这里调用了OrQuery的eval函数
        3.在调用AndQuery的eval函数和WordQuery的eval函数
        4.AndQuery的eval再调用WordQuery的eval函数

*/
