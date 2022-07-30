#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    stack<char> stack;
    string str;
    char c;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        c = str.at(i);
        if (c == ')')
        {
            if (stack.empty())
            {
                cout << "false";
                return 0;
            }
            if (stack.top() != '(')
            {
                // cout << "false";
                break;
            }
            stack.pop();
        }
        else if (c == '}')
        {
            if (stack.empty())
            {
                cout << "false";
                return 0;
            }
            if (stack.top() != '{')
            {
                // cout << "false";
                break;
            }
            stack.pop();
        }
        else if (c == ']')
        {
            if (stack.empty())
            {
                cout << "false";
                return 0;
            }
            if (stack.top() != '[')
            {
                // cout << "false";
                break;
            }
            stack.pop();
        }
        else if (c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
        }
    }
    if (stack.empty())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}