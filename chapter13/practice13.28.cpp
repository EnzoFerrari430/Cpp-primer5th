#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
public:
    TreeNode();
    //TreeNode(const string& s = string(),TreeNode *lchild = nullptr,TreeNode *rchild = nullptr);
    TreeNode(const string& s,TreeNode *lchild,TreeNode *rchild);
    ~TreeNode();
    TreeNode(const TreeNode& rhs);
    TreeNode& operator=(const TreeNode& rhs);
private:
    string value;
    int *count;  //引用计数,使用指针，共享元素
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode():value(""),count(new int(1)),left(nullptr),right(nullptr){}
//TreeNode::TreeNode(const string& s = string(),TreeNode *lchild = nullptr,TreeNode *rchild = nullptr):value(s),left(lchild),right(rchild),count(new int(1)){}
TreeNode::TreeNode(const string& s,TreeNode *lchild,TreeNode *rchild):value(s),left(lchild),right(rchild),count(new int(1)){}

TreeNode::TreeNode(const TreeNode& rhs)
{
    value = rhs.value;
    ++(*rhs.count);
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
}

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
    --(*count);
    if(*count == 0)
    {
        delete count;
        delete left;
        delete right;
    }
    ++(*rhs.count);
    count = rhs.count;
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

TreeNode::~TreeNode()
{
    --(*count);
    if( *count == 0 )
    {
        delete left;
        delete right;
        delete count;
    }
}

class BinStrTree
{
public:
    BinStrTree();
    BinStrTree(const BinStrTree& rhs);
    BinStrTree& operator=(const BinStrTree& rhs);
    ~BinStrTree(){delete root;}
private:
    TreeNode *root;
};

BinStrTree::BinStrTree():root(new TreeNode()){}
BinStrTree::BinStrTree(const BinStrTree& rhs)
{
    root = new TreeNode(*rhs.root);
}

BinStrTree& BinStrTree::operator=(const BinStrTree& rhs)
{
    TreeNode* new_root = new TreeNode(*rhs.root);
    delete root;
    root = new_root;
    return *this;
}


int main()
{

}
