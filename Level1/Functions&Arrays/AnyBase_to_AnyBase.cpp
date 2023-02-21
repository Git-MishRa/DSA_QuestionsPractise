#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int anybasetodecimal(int n, int b)
{
    int number = 0, i = 0;
    do
    {
        // cout << n << endl;

        number = n % 10 * (pow(b, i) + 1e-9) + number; // remember pow function is a double data type operated function
        // cout << number << endl;               //and pow is inaccurate with ints
        i++;
    } while (n = n / 10);
    return number;
}

int DecimaltoAnybaseconvert(int a, int b)
{
    vector<int> num;
    do
    {
        num.push_back(a % b); // storing the remainder to be printed
    } while (a = a / b);

    num.shrink_to_fit();
    for (int i = num.size() - 1; i >= 0; i--) // Length is 1 smaller than size of vector cuz indexing start at 0 to n-1
    {
        cout << num[i];
    }
}

int main()
{
    system("cls");
    int n, b, b1;
    cin >> n >> b >> b1;
    DecimaltoAnybaseconvert(anybasetodecimal(n, b), b1);
    return 0;
}