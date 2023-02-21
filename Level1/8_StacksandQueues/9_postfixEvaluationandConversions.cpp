#include <iostream>
#include <stack>
#include <string>
using namespace std;

int cal(int v1, int v2, char ch)
{
    if (ch == '+')
    {
        return v1 + v2;
    }
    else if (ch == '-')
    {
        return v1 - v2;
    }
    else if (ch == '*')
    {
        return v1 * v2;
    }
    else
    {
        return v1 / v2;
    }
}

int main()
{
    string input;
    getline(cin, input);
    stack<string> infix;
    stack<string> prefix;
    stack<char> operators;
    stack<int> nums;

    // Main for loop, string straversal
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input.at(i);
        if (isdigit(ch))
        {
            nums.push(ch - '0');
            string temp;
            infix.push(temp + ch);
            prefix.push(temp + ch);
            temp.clear();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            operators.push(ch);
            while (!operators.empty()) //&& priority(ch)<=priority(operators.top())
            {
                // char operator assign
                char c = operators.top();
                operators.pop();

                // calculation
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                nums.push(cal(v1, v2, c));
                // cout << nums.top() << "%" << i << endl;

                // infix coversion
                string s2 = infix.top();
                infix.pop();
                string s1 = infix.top();
                infix.pop();
                infix.push('(' + s1 + c + s2 + ')');

                // prefix coversion
                s2 = prefix.top();
                prefix.pop();
                s1 = prefix.top();
                prefix.pop();
                prefix.push(c + s1 + s2);
            }
        }
    }
    cout << nums.top() << endl
         << infix.top() << endl
         << prefix.top();
    return 0;
}

// 264*8/+3-

// 2
// ((2+((6*4)/8))-3) infix
// -+2/*6483   pre
