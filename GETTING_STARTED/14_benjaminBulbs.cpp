#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int arr[k + 1][1] = {0};
    for (int j = 1; j < k; j++)
    {
        for (int i = j; i < k; i = i + j)
        {
            if (arr[i][0] == 0)
            {
                arr[i][0] = 1;
            }
            else
            {
                arr[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < k; i++)
    {
        if (arr[i][0] == 1)
        {
            cout << i << endl;
        }
    }
    return 0;
}