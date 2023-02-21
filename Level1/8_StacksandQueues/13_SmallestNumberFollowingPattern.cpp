#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> st;

    //

    int count = 1;
    for (int i = 0; i < str.length(); i++)
    {
        char x = str.at(i);
        if (x == 'd')
        {
            st.push(count);
            count++;
        }

        if (x == 'i')
        {

            st.push(count);
            count++;
            while (!st.empty())
            {
                int a = st.top();
                cout << a;
                st.pop();
            }
        }
    }
    st.push(count);
    while (!st.empty())
    {
        int a = st.top();
        cout << a;
        st.pop();
    }
    return 0;
}

// ddddiiii

// 543216789
