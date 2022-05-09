#include <iostream>
using namespace std;

int main()
{
    int n1, n2, m1, m2;
    cin >> n1 >> m1;
    int arr1[n1][m1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cin >> n2 >> m2;
    int arr2[n2][m2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> arr2[i][j];
        }
    }
    return 0;
}