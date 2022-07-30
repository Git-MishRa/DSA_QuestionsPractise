#include <iostream>
using namespace std;
void toh(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    toh(n - 1, a, c, b);
    cout << "Move disk " << n << " from " << a << " to " << b << endl;
    toh(n - 1, c, b, a);
}
int main()
{
    toh(3, 'A', 'B', 'C');
    return 0;
}