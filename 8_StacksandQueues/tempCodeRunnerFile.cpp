#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // variables
    // stack<int> start;
    // stack<int> end;
    int starr[n];
    int endarr[n];
    int rst[n];
    int rend[n];

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> starr[i];
        cin >> endarr[i];
    }

    // sorting using sort fn from algorith header file
    sort(starr, starr + n);
    sort(endarr, endarr + n);

    //
    for (int i = 0; i < n - 1; i++)
    {
        if (endarr[i] >= starr[i + 1])
        {
            rst[i] = starr[i];
            rend[i] = endarr[i + 1];
            i++;
        }
        else
        {
            rst[i] = starr[i];
            rend[i] = endarr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << rst[i] << " " << rend[i] << endl;
    }

    return 0;
}