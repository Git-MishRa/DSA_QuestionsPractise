#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int n1, n2, diff;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    if (n1 > n2)
    {
        int arr[n1];
        diff = n1 - n2;
        int temp = diff;
        while (temp != 0)
        {
            int i = 0;
            arr[i] = arr1[i];
            cout << arr[i] << endl;
            temp--;
        }
        for (int i = 0; i < n2; i++)
        {
            arr[i] = arr1[i + diff] + arr2[i];
            cout << arr[i + diff] << endl;
        }
    }
    else
    {
        int arr[n2];
        diff = n2 - n1;
        int temp = diff;
        while (temp != 0)
        {
            int i = 0;
            arr[i] = arr2[i];
            cout << arr[i] << endl;
            temp--;
        }
        for (int i = 0; i < n1; i++)
        {
            arr[i + diff] = arr2[i + diff] + arr1[i];
            cout << arr[i + diff] << endl;
        }
    }
}