#include <iostream>
using namespace std;

void displayArr(int arr[], int n)
{
    if (n == 0)
    {
        cout << arr[n] << endl;
        return;
    }
    cout << arr[n - 1] << endl;
    displayArr(arr, n - 1);
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
    displayArr(arr, n);
    return 0;
}