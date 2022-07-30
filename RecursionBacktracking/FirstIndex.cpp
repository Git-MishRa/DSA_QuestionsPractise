#include <iostream>
using namespace std;

int firstIndex(int arr[], int n, int x)
{
    if (n == 0)
    {
        return arr[n];
    }
    if (arr[n] == x)
    {
        return n;
    }
    else
    {
        firstIndex(arr, n - 1, x);
    }
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
    cout << firstIndex(arr, n, x);
    return 0;
}