#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // window input
    cin >> k;

    // finding next greater and storing it in an array
    stack<int> st;
    int nge[n];
    nge[n - 1] = n;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        x = arr[i];
        while (!st.empty() && x >= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            nge[i] = n;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(i);
    }

    // Sliding window
    int j;
    for (int i = 0; i <= n - k; i++)
    {
        if (j < i)
        {
            j = i;
        }
        while (nge[j] < i + k)
        {
            j = nge[j];
        }
        cout << arr[j] << endl;
    }
    return 0;
}