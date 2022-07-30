#include <iostream>
using namespace std;

int maxOfArray(int arr[], int n)
{
    if (n == 0)
    {
        return arr[n];
    }
    if (arr[n] < maxOfArray(arr, n - 1))
    {
        return maxOfArray(arr, n - 1);
    }
    else
    {
        return arr[n];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxOfArray(arr, n);
    return 0;
}