#include <iostream>
using namespace std;

void printDecreasing(int a)
{
    if (a == 0)
    {
        return;
    }
    cout << a << endl;
    printDecreasing(a - 1);
}

int main()
{
    int n;
    cin >> n;
    printDecreasing(n);
    return 0;
}