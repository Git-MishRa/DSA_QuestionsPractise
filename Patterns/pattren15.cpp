#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        k = i;
        for (int j = 0; j < n; j = j++)
        {
            if (j == n / 2 && i <= n / 2)
            {
                cout << k + 1 << "    ";
                k = k + 2;
            }
        }
    }
    return 0;
}