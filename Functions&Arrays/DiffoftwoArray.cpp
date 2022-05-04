#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n1, n2, diff, num1, num2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        int k = n1;
        cin >> arr1[i];
        num1 = arr1[i] * (pow(10, k) + 1e-9) + num1;
        k--;
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        int k = n2;
        cin >> arr2[i];
        num2 = arr2[i] * (pow(10, k) + 1e-9) + num2;
        k--;
    }
    cout << num2 - num1;
    return 0;
}