#include <iostream>
#include <exception>
#include <queue>
using namespace std;

class QueueToStackAdapter
{
public:
    queue<int> mainQ;
    queue<int> helperQ;

    int size()
    {
        // write your code here
        return mainQ.size();
    }

    void push(int data)
    {
        // write your code here
        mainQ.push(data);
    }

    int top()
    {
        // write your code here
        return mainQ.back();
    }

    int pop()
    {
        // write your code here
        while (mainQ.size() > 1)
        {
            helperQ.push(mainQ.front());
            mainQ.pop();
        }
        int rval = mainQ.front();
        mainQ.pop();
        while (!helperQ.empty())
        {
            mainQ.push(helperQ.front());
            helperQ.pop();
        }
        return rval;
    }
};

int main()
{
    QueueToStackAdapter st;
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
        cin >> str;
    }
    return 0;
}