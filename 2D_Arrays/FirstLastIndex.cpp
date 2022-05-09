#include <iostream>
using namespace std;

int main()
{
    int n, d, count = 0, end;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> d;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == d)
        {
            end = i;
            count++;
        }
    }
    cout << end - count + 1 << endl
         << end;
    return 0;
}