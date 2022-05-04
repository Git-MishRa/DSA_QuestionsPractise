#include <iostream>
using namespace std;

int carryg(int a)
{
    if (a / 10 > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int subtract(int b,int n1,int n2,int borrow){
    do
    {
        if (n1 % 10 < n2 % 10)
        {
            borrow = carryg(n1);
            n1=(n1%10+(borrow*b))-n2%10;
        }
}
}

int main()
{
    int b, n1, n2, result = 0, borrow;
    cin >> b, n1, n2;
    do
    {
        if (n1 % 10 < n2 % 10)
        {
            borrow = carryg(n1);
            if(borrow==1){
                n1=n1/10
            }
        }
        result = (n1 % 10 + (b * borrow) - n2 % 10) + result
    }
    return 0;
}