#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    system("cls");
    int b, n1, n2, carry = 0, sum, i = 0, result = 0;
    cin >> b >> n1 >> n2;
    //
    if (n2 > n1)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }

    do
    {
        sum = (((n1 % 10 + n2 % 10 + carry) % b)) * (pow(10, i) + 1e-9);
        result = result + sum;
        // cout << result << endl;
        if ((n1 % 10 + n2 % 10 + carry) >= b)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        i++;
        n2 = n2 / 10;
    } while (n1 = n1 / 10);
    if (carry == 1)
    {
        result = result + (pow(10, i) + 1e-9);
    }
    cout << result;
    return 0;
}