// #include <iostream>
// using namespace std;

// int Factorial(int a)
// {
//     if (a == 0)
//     {
//         return 1;
//     }
//     cout << a * (Factorial(a - 1));     // This doesn;t work
// }

// int main()
// {
//     int n;
//     cin >> n;
//     Factorial(n);
//     return 0;
// }

#include <iostream>
using namespace std;

int Factorial(int a)
{
    if (a == 0)
    {
        return 1;
    }
    return a * Factorial(a - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << Factorial(n);
    return 0;
}