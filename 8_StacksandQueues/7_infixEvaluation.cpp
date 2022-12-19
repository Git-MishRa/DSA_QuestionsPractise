#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch)
{
    if (ch == '+')
    {
        return 1;
    }
    else if (ch == '-')
    {
        return 1;
    }
    else if (ch == '*')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}

int operation(char ch, int n1, int n2)
{
    if (ch == '+')
    {
        return n1 + n2;
    }
    else if (ch == '-')
    {
        return n1 - n2;
    }
    else if (ch == '*')
    {
        return n1 * n2;
    }
    return n1 / n2;
}

int main()
{
    int n1, n2;
    char ch;
    string str;
    getline(cin, str);
    // cout << str.length();
    stack<char> optor;
    stack<int> opnd;
    char opt;
    for (int i = 0; i < str.length(); i++)
    {
        ch = str.at(i);
        if (ch == '(')
        {
            optor.push(ch);
        }
        else if (ch == ')')
        {
            while (optor.top() != '(')
            {
                opt = optor.top();
                optor.pop();
                n2 = opnd.top();
                opnd.pop();
                n1 = opnd.top();
                opnd.pop();
                opnd.push(operation(opt, n1, n2));
            }
            optor.pop();
        }
        else if (isdigit(ch))
        {
            opnd.push(ch - '0'); // char to int coversion
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            // cout << ch << endl;
            while (!optor.empty() && optor.top() != '(' && priority(ch) <= priority(optor.top()))
            {
                opt = optor.top();
                optor.pop();
                n2 = opnd.top();
                opnd.pop();
                n1 = opnd.top();
                opnd.pop();
                opnd.push(operation(opt, n1, n2));
            }
            optor.push(ch);
        }
    }
    while (!optor.empty())
    {
        opt = optor.top();
        optor.pop();
        n2 = opnd.top();
        opnd.pop();
        n1 = opnd.top();
        opnd.pop();
        opnd.push(operation(opt, n1, n2));
    }
    cout << opnd.top();
    return 0;
}