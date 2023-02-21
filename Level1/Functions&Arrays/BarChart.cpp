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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // regular matrix of nXn
        {
            if (arr[j] >= n - i) // The logic: print stars only if the height of bar chart is enough else print space
            {
                cout << "*"
                     << "    ";
            }
            else
            {
                cout << "     ";
            }
        }
        cout << endl;
    }
    return 0;
}