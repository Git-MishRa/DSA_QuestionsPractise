#include <iostream>
using namespace std;

void printIncreasing(int a)
{
    if (a == 0)
    {
        return;
    }
    printIncreasing(a - 1);
    cout << a << endl;
}
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
    printIncreasing(n);
    return 0;
}