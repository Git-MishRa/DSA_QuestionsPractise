#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, x;
    stack<int> stack;
    cin >> n;
    int arr[n]; // BAD PRACTICE, DO NOT ALLOCATE ARRAY OF UNKNOWN SIZE (at compile time)
    // int ngel[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // ngel[0] = -1;
    cout << -1 << endl;
    stack.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        x = arr[i];
        while (!stack.empty() && x >= stack.top())
        {
            stack.pop();
        }
        if (stack.empty())
        {
            // ngel[i] = -1;
            cout << -1 << endl;
        }
        else
        {
            // ngel[i] = stack.top();
            cout << stack.top() << endl;
        }
        stack.push(x);
    }
    return 0;
}
