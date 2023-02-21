#include <iostream>
using namespace std;

int main()
{
    int count, max = 0, min = 99999;
    cin >> count;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << max - min << endl;
    return 0;
}