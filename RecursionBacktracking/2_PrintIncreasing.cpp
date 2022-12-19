#include <iostream>
using namespace std;

void printIncreasing(int a)
{
    if (a == 0)
    {
        return; // are you stupid nigga? ye nhi soch pa re the?
    }
    printIncreasing(a - 1);
    cout << a << endl;
}

int main()
{
    int n;
    cin >> n;
    printIncreasing(n);
    return 0;
}