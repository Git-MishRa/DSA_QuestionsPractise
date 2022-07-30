#include <iostream>
using namespace std;

void lastIndex(int arr[], int n, int x)
{
    if (n == 0 && arr[n] == x)
    {
        cout << n;
        return;
    }
    else if (n == 0)
    {
        return;
    }
    if (arr[n] == x)
    {
        cout << n;
        return;
    }
    lastIndex(arr, n - 1, x);
}

int main()
{
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    lastIndex(arr, n, x);
    return 0;
}