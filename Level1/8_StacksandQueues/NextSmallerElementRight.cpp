#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, x;
    stack<int> stack;
    cin >> n;
    int arr[n];
    int nse[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    nse[n - 1] = -1;
    stack.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        x = arr[i];
        while (!stack.empty() && x <= stack.top())
        {
            stack.pop();
        }
        if (stack.empty())
        {
            nse[i] = -1;
        }
        else
        {
            nse[i] = stack.top();
        }
        stack.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nse[i] << endl;
    }
    return 0;
}