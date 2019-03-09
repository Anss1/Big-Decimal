#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <algorithm>
using namespace std;


class BigDecimalInt
{
    int *arr,size_s;
    string str;
    char sign ;
public:
    BigDecimalInt();
    BigDecimalInt(int);
    BigDecimalInt(string );
    BigDecimalInt operator =(BigDecimalInt );

    BigDecimalInt operator+(BigDecimalInt );
    BigDecimalInt operator-(BigDecimalInt );
    int returnsize();

    friend ostream& operator<< (ostream&, BigDecimalInt& );

    ~BigDecimalInt();

};

#endif // BIGDECIMALINT_H
