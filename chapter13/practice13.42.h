#ifndef PRACTICE13_42_H_INCLUDED
#define PRACTICE13_42_H_INCLUDED

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include <sstream>
#include "StrVec.h"
using namespace std;

class QueryResult;
class TextQuery
{
public:
    //using LineNo = vector<string>::size_type;  //用size_t代替
    using LineNo = size_t;
    TextQuery(ifstream &infile);  //构造函数
    QueryResult query(const string&) const;

public:
    StrVec sTxts;  //输入的文本
    map<string,set<int>> row;  //单词出现的行

    //shared_ptr<vector<string>> input;  //用StrVec代替
    shared_ptr<StrVec> input;
    map<string,shared_ptr<set<LineNo>>> result;


};

class QueryResult
{
public:
    friend ostream &print(ostream &,const QueryResult&);
public:
    //QueryResult(const string &s,shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v):word(s), nos(set), input(v){}  //  vector<string> 用StrVec代替
    QueryResult(const string &s,shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<StrVec> v): word(s),nos(set),input(v){}
private:
    string word;
    shared_ptr<StrVec> input;
    shared_ptr<set<TextQuery::LineNo>> nos;
};

#endif // PRACTICE13_42_H_INCLUDED
