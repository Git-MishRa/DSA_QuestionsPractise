#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int n, d, count = 0;
    cin >> n >> d;
    do
    {
        if (n % 10 == d)
        {
            count++;
        }
    } while (n = n / 10);
    cout << count << endl;
    return 0;
}