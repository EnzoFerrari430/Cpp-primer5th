#include <iostream>
#include "Bulk_quote.h"
using namespace std;

int main()
{
    Quote q1;
    Bulk_quote b1;
    Quote q2(q1);
    Quote q3(std::move(q1));


    return 0;
}
