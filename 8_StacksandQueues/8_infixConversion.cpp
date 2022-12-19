#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch)
{
    if (ch == '+' || ch == '-')
    {
        // cout << ch << "&" << endl;
        return 1;
    }

    else if (ch == '*' || ch == '/')
    {
        // cout << ch << "%" << endl;
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string str;
    getline(cin, str);
    stack<string> post;
    stack<string> pre;
    stack<char> ops;
    string tempstr;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);

        if (ch == '(')
        {
            ops.push(ch);
        }
        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            post.push(tempstr + ch);
            tempstr.clear();
            pre.push(tempstr + ch);
            tempstr.clear();
        }
        else if (ch == ')')
        {
            while (ops.top() != '(')
            {
                char opp = ops.top();
                ops.pop();
                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();
                post.push(postv1 + postv2 + opp);

                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();
                pre.push(opp + prev1 + prev2);
            }
            ops.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!ops.empty() && ops.top() != '(' && priority(ch) <= priority(ops.top()))
            {
                char opp = ops.top();
                ops.pop();
                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();
                post.push(postv1 + postv2 + opp);

                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();
                pre.push(opp + prev1 + prev2);
            }
            ops.push(ch);
        }
    }
    while (!ops.empty())
    {
        char opp = ops.top();
        ops.pop();
        string postv2 = post.top();
        post.pop();
        string postv1 = post.top();
        post.pop();
        post.push(postv1 + postv2 + opp);

        string prev2 = pre.top();
        pre.pop();
        string prev1 = pre.top();
        pre.pop();
        pre.push(opp + prev1 + prev2);
    }

    cout << post.top() << endl
         << pre.top();

    return 0;
}