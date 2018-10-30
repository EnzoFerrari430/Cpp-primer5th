#ifndef PRACTICE12_32_H_INCLUDED
#define PRACTICE12_32_H_INCLUDED

#include "practice12.22.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;


class QueryResult;
class TextQuery
{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(ifstream &infile);  //构造函数
    QueryResult query(const string&) const;

public:
    vector<string> sTxts;  //输入的文本
    map<string,set<int>> row;  //单词出现的行

    StrBlob input;
    map<string,shared_ptr<set<LineNo>>> result;


};

class QueryResult
{
public:
    using ResultIter = std::set<StrBlob::size_type>::iterator;
    friend ostream &print(ostream &,const QueryResult&);
public:
    QueryResult(const string &s,shared_ptr<std::set<StrBlob::size_type>> set, const StrBlob& v):word(s), nos(set), input(v){}
    ResultIter begin(){return nos->begin();}
    ResultIter end(){return nos->end();}
    shared_ptr<StrBlob> get_file()const{return make_shared<StrBlob>(input);}

private:
    string word;
    StrBlob input;
    shared_ptr<set<StrBlob::size_type>> nos;
};

ostream& print(ostream&,const QueryResult&);

void runQueries(ifstream &infile);
std::ostream& print(std::ostream &out,const QueryResult& qr);

#endif // PRACTICE12_32_H_INCLUDED
