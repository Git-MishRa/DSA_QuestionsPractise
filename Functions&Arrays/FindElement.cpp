#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int count, num, c = 0;
    cin >> count;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    cin >> num;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == num)
        {
            cout << i << endl;
            c++;
            break;
        }
    }
    if (c == 0)
    {
        cout << -1 << endl;
    }
    return 0;
}