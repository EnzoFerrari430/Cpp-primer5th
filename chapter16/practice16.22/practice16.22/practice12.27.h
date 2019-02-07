#ifndef PRACTICE12_27_H_INCLUDED
#define PRACTICE12_27_H_INCLUDED
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
#include "debugdelete.h"
using namespace std;

using LineNo = vector<string>::size_type;
class QueryResult;
class TextQuery
{
public:
    TextQuery(ifstream &infile);  //¹¹Ôìº¯Êý
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> input;
    shared_ptr<map<string,set<LineNo>>> result;


};

class QueryResult
{
public:
    friend ostream &print(ostream &,const QueryResult&);
public:
    QueryResult(size_t c,const string &s,const shared_ptr<vector<string>> &st, const shared_ptr<map<string, set<LineNo>>> &v):counter(c),word(s), input(st), nos(v){}
private:
	size_t counter = 0;
    string word = "";
	shared_ptr<vector<string>> input;
	shared_ptr<map<string, set<LineNo>>> nos;
};


#endif // PRACTICE12_27_H_INCLUDED
