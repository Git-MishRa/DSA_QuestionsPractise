#include <iostream>
using namespace std;

int main()
{
    int n, d;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> d;
    for (int i = 0; i < n; i++)
    {
        if (d == arr[i])
        {
            cout << d;
            break;
        }
        if (arr[i] > d)
        {
            cout << arr[i - 1] << "   " << arr[i] << endl;
            break;
        }
    }

    return 0;
}