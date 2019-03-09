#include "BigDecimalInt.h"

int main()
{
//    cout<<555-509<<endl;
//    return 0;
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("113456789011345678901134567890");
    BigDecimalInt num3 = num2 + num1;
    cout<<"Num3 = "<<num3<<endl;

    BigDecimalInt num4("-123456789012345678901234567890");
    BigDecimalInt num5("113456789011345678901134567890");
    BigDecimalInt num6 = num4 + num5;
    cout<<"Num6 = "<<num6<<endl;

    BigDecimalInt num7("-123456789012345678901234567890");
    BigDecimalInt num8("-113456789011345678901134567890");
    BigDecimalInt num9 = num7 + num8;
    cout<<"Num9 = "<<num9<<endl;

    BigDecimalInt num10("123456789012345678901234567890");
    BigDecimalInt num11("113456789011345678901134567890");
    BigDecimalInt num12 = num10 - num11;
    cout<<"Num12 = "<<num12<<endl;

    BigDecimalInt num13("123456789012345678901234567890");
    BigDecimalInt num14("-113456789011345678901134567890");
    BigDecimalInt num15 = num13 - num14;
    cout<<"Num15 = "<<num15<<endl;

    return 0;
}
