#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    stack<int> st;
    int arr[n][n];
    // Input
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = str.at(j) - '0';
        }
        str.clear();
        st.push(i);
    }

    // Elimination round
    while (st.size() > 1)
    {
        int n1 = st.top();
        st.pop();
        int n2 = st.top();
        st.pop();
        if (arr[n1][n2] == 1)
        {
            st.push(n2);
        }
        else
        {
            st.push(n1);
        }
    }

    // Final check
    int x = st.top();
    st.pop();
    for (int i = 0; i < n; i++)
    {
        if (i != x)
        {
            if (arr[x][i] == 1 || arr[i][x] == 0)
            {
                cout << "none";
                return 0;
            }
        }
    }
    cout << x;
    return 0;
}