#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int count = 0, j;
    string str;
    // cin.ignore(100, " ");
    // cin >> str;
    getline(cin, str); // Had to use getline because cin stops input after each white space
    stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str.at(i);
        if (c == ')')
        {
            if (stack.top() == '(')
            {
                cout << "true";
                return 0;
            }
            while (stack.top() != '(')
            {
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            stack.push(c);
        }
    }
    cout << "false";
    // cout << str.length();

    return 0;
}
