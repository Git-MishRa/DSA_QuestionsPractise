#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    system("cls");
    int n, b, number = 0, i = 0;
    cin >> n >> b;
    do
    {
        // cout << n << endl;

        number = n % 10 * (pow(b, i) + 1e-9) + number; // remember pow function is a double data type operated function
        // cout << number << endl;               //and pow is inaccurate with ints
        i++;
    } while (n = n / 10);
    cout << number;
    return 0;
}