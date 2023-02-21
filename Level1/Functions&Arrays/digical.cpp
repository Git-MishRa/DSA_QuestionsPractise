#include <iostream>
using namespace std;
int main()
{
    int n = 1234567;
    int count = 0;
    for (int i = n; i != 0; i /= 10, count++);
    cout << count;
    return 0;
}