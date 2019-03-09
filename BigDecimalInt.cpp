#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(){};
BigDecimalInt BigDecimalInt:: operator =(BigDecimalInt big)
{
    BigDecimalInt temp;
    temp.sign=big.sign;
    temp.size_s=big.size_s;
    temp.str=big.str;
    temp.arr=new int[big.size_s];
    for(int i=0;i<big.size_s;i++)
        temp.arr[i]=big.arr[i];
    return temp;
}

BigDecimalInt::BigDecimalInt(int decint)
{
    arr = new int [decint];
    size_s = decint;
}

BigDecimalInt::BigDecimalInt(string decstr)
{
    if(decstr[0] == '-')
    {
        sign = '-';
        size_s = decstr.size()-1;
        arr = new int[size_s];
        reverse(decstr.begin(),decstr.end());
        for(int i=0 ; i< size_s; i++)
        {
            arr[i] = decstr[i] - '0';
            str+=decstr[i];
        }
    }
    else
    {
        sign = '+';
        size_s = decstr.size();
        arr = new int[size_s];
        reverse(decstr.begin(),decstr.end());
        for(int i=0 ; i< size_s; i++)
        {
            arr[i] = decstr[i] - '0';
            str+=decstr[i];
        }
    }
}
int BigDecimalInt::returnsize()
{
    return size_s;
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt big)
{
    BigDecimalInt temp(size_s);
    short rem,div=0;
    bool val=false;
    if(size_s > big.size_s)//to make the size of each array is equal
    {
        delete[]big.arr;
        big.arr=new int[size_s];
        for(int i=0; i<size_s; i++)
        {
            if(i<big.size_s)
                big.arr[i]=big.str[i]-'0';
            else
                big.arr[i]=0;
        }
    }
    else if(size_s < big.size_s)
    {
        delete[]arr;
        arr=new int[big.size_s];
        for(int i=0; i<big.size_s; i++)
        {
            if(i<size_s)
                arr[i]=str[i]-'0';
            else
                arr[i]=0;
        }
    }
    for(int i=size_s-1; i>=0; i--)//to know the sign of the biggest number
    {
        if(arr[i] > big.arr[i])
        {
            val=true;
            break;
        }
        else if(arr[i] < big.arr[i])
        {
            break;
        }
    }//*******************************************************************

    if((sign == '+'&&big.sign == '+') || (sign == '-'&&big.sign == '-'))
    {
        for(int i=0; i<size_s; i++)
        {
            rem=(arr[i]+big.arr[i])%10;
            temp.arr[i]=rem+div;
            div=(arr[i]+big.arr[i])/10;
        }
    }
    else
    {
        if(val)
        {
            for(int i=0; i<size_s; i++)
            {
                if(arr[i] < big.arr[i])
                {
                    if(arr[i+1]!=0)
                    {
                        arr[i+1]--;
                        arr[i]+=10;
                        temp.arr[i]=arr[i]-big.arr[i];
                    }
                    else
                    {
                        for(int j=i+1; j<size_s; j++)
                        {
                            if(arr[j]!=0)
                            {
                                arr[j]--;
                                arr[i]+=10;
                                temp.arr[i]=arr[i]-big.arr[i];
                            }
                            else
                                arr[j]=9;
                        }
                    }
                }
                else
                    temp.arr[i]=arr[i]-big.arr[i];
            }
        }
        else
        {
            for(int i=0; i<size_s; i++)
            {
                if(arr[i] > big.arr[i])
                {
                    if(big.arr[i+1]!=0)
                    {
                        big.arr[i+1]--;
                        big.arr[i]+=10;
                        temp.arr[i]=big.arr[i]-arr[i];
                    }
                    else
                    {
                        for(int j=i+1; j<size_s; j++)
                        {
                            if(big.arr[j]!=0)
                            {
                                big.arr[j]--;
                                big.arr[i]+=10;
                                temp.arr[i]=big.arr[i]-arr[i];
                            }
                            else
                                big.arr[j]=9;
                        }
                    }
                }
                else
                    temp.arr[i]=big.arr[i]-arr[i];
            }
        }
    }
    (val? temp.sign=sign : temp.sign=big.sign);
    return temp;
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt big)
{
    BigDecimalInt temp(size_s);
    bool val =false;
    short rem,div=0;
    if(size_s > big.size_s)//to make the size of each array is equal
    {
        delete[]big.arr;
        big.arr=new int[size_s];
        for(int i=0; i<size_s; i++)
        {
            if(i<big.size_s)
                big.arr[i]=big.str[i]-'0';
            else
                big.arr[i]=0;
        }
    }
    else if(size_s < big.size_s)
    {
        delete[]arr;
        arr=new int[big.size_s];
        for(int i=0; i<big.size_s; i++)
        {
            if(i<size_s)
                arr[i]=str[i]-'0';
            else
                arr[i]=0;
        }
    }
    for(int i=size_s-1; i>=0; i--)//to know the sign of the biggest number
    {
        if(arr[i] > big.arr[i])
        {
            val=true;
            break;
        }
        else if(arr[i] < big.arr[i])
        {
            break;
        }
    }//*******************************************************************
    if((sign == '+'&&big.sign == '+')||(sign == '-'&&big.sign == '-'))
    {
        if(val)
        {
            for(int i=0; i<size_s; i++)
            {
                if(arr[i] < big.arr[i])
                {
                    if(arr[i+1]!=0)
                    {
                        arr[i+1]--;
                        arr[i]+=10;
                        temp.arr[i]=arr[i]-big.arr[i];
                    }
                    else
                    {
                        for(int j=i+1; j<size_s; j++)
                        {
                            if(arr[j]!=0)
                            {
                                arr[j]--;
                                arr[i]+=10;
                                temp.arr[i]=arr[i]-big.arr[i];
                            }
                            else
                                arr[j]=9;
                        }
                    }
                }
                else
                    temp.arr[i]=arr[i]-big.arr[i];
            }
        }
        else
        {
            for(int i=0; i<size_s; i++)
            {
                if(arr[i] > big.arr[i])
                {
                    if(big.arr[i+1]!=0)
                    {
                        big.arr[i+1]--;
                        big.arr[i]+=10;
                        temp.arr[i]=big.arr[i]-arr[i];
                    }
                    else
                    {
                        for(int j=i+1; j<size_s; j++)
                        {
                            if(big.arr[j]!=0)
                            {
                                big.arr[j]--;
                                big.arr[i]+=10;
                                temp.arr[i]=big.arr[i]-arr[i];
                            }
                            else
                                big.arr[j]=9;
                        }
                    }
                }
                else
                    temp.arr[i]=big.arr[i]-arr[i];
            }
        }
    }
    else
    {
        for(int i=0; i<size_s; i++)
        {
            rem=(arr[i]+big.arr[i])%10;
            temp.arr[i]=rem+div;
            div=(arr[i]+big.arr[i])/10;
        }
    }
    (val? temp.sign=sign : temp.sign=big.sign);
    return temp;
}

ostream &operator<< (ostream& out,BigDecimalInt& obj)
{
    if(obj.sign=='-')
        out<<obj.sign;
    for(int i=obj.size_s-1; i>=0; i--)
    {
        out<<obj.arr[i];
    }
    out<<endl;
    return out;
}



BigDecimalInt::~BigDecimalInt()
{
    delete[] arr;
}
