#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < 11; i++)
    {
        cout << "3 * " << i << " = " << n * i << endl;
    }
    return 0;
}