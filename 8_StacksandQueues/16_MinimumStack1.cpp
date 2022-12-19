#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack
{
    stack<int> data;
    stack<int> minVal;

public:
    int size()
    {
        // write your code here
        return data.size();
    }

public:
    void push(int val)
    {
        // write your code here
        data.push(val);
        // remember if the val is equal to minval.top push the val again
        if (minVal.empty() || val <= minVal.top())
        {
            minVal.push(val);
        }
    }

public:
    int pop()
    {
        // write your code here
        int a = data.top();
        data.pop();
        if (a == minVal.top())
        {
            minVal.pop();
        }
        return a;
    }

public:
    int top()
    {
        // write your code here
        return data.top();
    }

public:
    int min()
    {
        // write your code here
        if (!minVal.empty())
        {
            return minVal.top();
        }
        else
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }
};

int main()
{
    MinStack st;

    string str;
    cin >> str;

    while (str != "quit")
    {

        if (str == "push")
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (str == "pop")
        {
            int val = st.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "top")
        {
            int val = st.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        else if (str == "min")
        {
            int val = st.min();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        cin >> str;
    }
}