#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int n, x;
    cin >> n;
    int arr[n];
    int nge[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    nge[n - 1] = -1;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        x = arr[i];
        while (!st.empty() && x >= st.top())
        {
            st.pop();
        }
        if (st.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << endl;
    }
    return 0;
}
