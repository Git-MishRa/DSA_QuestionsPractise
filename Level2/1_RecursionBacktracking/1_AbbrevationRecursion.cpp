#include <iostream>
#include <string>
using namespace std;
void solution(string str, string asf, int count, int pos)
{
    // write your code here
    // base case
    if (pos == str.length())
    {
        if (count == 0)
        {
            cout << asf << endl;
        }
        else
        {
            cout << asf + to_string(count) << endl;
        }
        return;
    }

    // calls firts for yes and then no, as per the answer requirements
    if (count > 0)
    {
        // string temp = asf;
        // temp += to_string(count);
        // temp += str.at(pos);
        // call
        solution(str, asf + to_string(count) + str.at(pos), 0, pos + 1);
    }
    else
    {
        // string temp = asf;
        // temp += str.at(pos);
        // call
        solution(str, asf + str.at(pos), 0, pos + 1);
    }
    // call for NO i.e, when we didn't select the char
    solution(str, asf, count + 1, pos + 1);
}
int main()
{
    string str;
    cin >> str;
    solution(str, "", 0, 0);
    return 0;
}