#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int b, n1, n2, borrow = 0, result = 0, i = 0;
    cin >> b >> n1 >> n2;

    // n2-n1

    do
    {
        if (n2 % 10 < n1 % 10 && n2 / 10 > 0)
        {
            borrow = 1;
            n2 = n2 - 10;                        // this is causing the issue find a way to manage the borrow from the number
            result = ((n2 % 10 + borrow * b) - n1 % 10) * pow(10, i) + result;
            i++;
        }
        else if (n2 % 10 > n1 % 10)
        {
            result = ((n2 % 10) - n1 % 10) * pow(10, i) + result;
        }
        n2 = n2 / 10;
        n1 = n1 / 10;

    } while (n2 != 0);
    cout << result;
    return 0;
}