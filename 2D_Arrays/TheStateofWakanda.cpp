#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    for (int j = 0; j < m; j++) // Keeping the column undisturbed, i.e. incrementing one by one
    {
        for (int i = 0; i < n; i++) // basic row loop
        {
            if (j % 2 == 0) // printing normal i j value for even columns
            {
                cout << arr[i][j] << endl;
            }
            else
            {
                cout << arr[n - i - 1][j] << endl; // traversing backwards for odd values of column 
            }
        }
    }
    return 0;
}