#include <iostream>
using namespace std;

int main()
{
    int n, flag = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            cout << "Comparing " << arr[i + 1] << " and " << arr[i] << endl;
            if (arr[i] > arr[i + 1])
            {
                cout << "Swapping " << arr[i + 1] << " and " << arr[i] << endl;
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                flag++;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

    return 0;
}