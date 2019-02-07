#include <string>


//这些模板类必须在程序其他位置进行实例化
extern template class Blob<std::string>;
extern template int compare(const int&, const int&);