#include <iostream>
using namespace std;

int main()
{
    int n, last = 0, penlast = 1, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << result << "    ";
            result = last + penlast;
            penlast = last;
            last = result;
        }
        cout << endl;
    }
}
