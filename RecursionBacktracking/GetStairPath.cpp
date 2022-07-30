#include <iostream>
using namespace std;

void stairsPath(int n, string s)
{
    if (n <= 0)
    {
        if (n == 0)
        {
            cout << s << ", ";
        }
        return;
    }
    stairsPath(n - 1, s + to_string(1));
    stairsPath(n - 2, s + to_string(2));
    stairsPath(n - 3, s + to_string(3));
}

int main()
{
    int n;
    string s;
    cin >> n;
    cout << "[";
    stairsPath(n, s);
    cout << "]";
    return 0;
}