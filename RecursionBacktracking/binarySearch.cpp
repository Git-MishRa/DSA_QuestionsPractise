#include <iostream>
using namespace std;

void binarySearch(int arr[], int x, int min, int max)
{
    if (max == 0)
    {
        return;
    }
    if (arr[(min + max) / 2] == x)
    {
        cout << (min + max) / 2;
        return;
    }
    else if (arr[(min + max) / 2] > x)
    {
        binarySearch(arr, x, min, ((min + max) / 2) + 1);
    }
    else
    {
        binarySearch(arr, x, ((min + max) / 2) + 1, max);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6, x = 3;
    binarySearch(arr, x, 0, 6);
    return 0;
}