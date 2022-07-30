#include <iostream>
#include <stack>
using namespace std;

int main()
{

    int n, x;
    stack<int> st;
    cin >> n;
    int arr[n];
    int span[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    span[0] = 1;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        x = arr[i];
        while (!st.empty() && x > arr[st.top()])
        {
            st.pop();
            // j++;
            // Can not print based on while loop count, it fails when stack in not empty and the top is already greater
        }
        if (st.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - st.top();
        }
        st.push(i);
        // j = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << endl;
    }

    return 0;
}
