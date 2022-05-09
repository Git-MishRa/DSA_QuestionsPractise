#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) // need to format the output so it can match that of array list
    {
        for (int j = 2; j * j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                cout << arr[i] << "    ";
                break;
            }
        }
    }

    return 0;
}