#include <iostream>
using namespace std;

// SHITENDU MISHRA

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // for the left half of the pattern
        {
            if (i >= j)
            {
                cout << j + 1 << "    ";
            }
            else
            {
                cout << "     ";
            }
        }
        for (int k = 0; k < n - 1; k++) // for the right half of pattern
        {
            if (i + k < n - 2 || i + k == 0) // firstly printing all spaces in the pattern in aparticular line
            {
                cout << "     ";
            }
            else
            {
                cout << n - 1 - k << "    "; // value to be printed
            }
        }
        cout << endl;
    }
    return 0;
}