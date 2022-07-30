#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, x;
    stack<int> stack;
    cin >> n;
    int arr[n];
    int nsel[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack.push(arr[0]);
    cout << -1 << endl;
    for (int i = 1; i < n; i++)
    {
        x = arr[i];
        while (!stack.empty() && x <= stack.top())
        {
            stack.pop();
        }
        if (stack.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << stack.top() << endl;
        }
        stack.push(x);
    }

    return 0;
}