#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, result;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s.at(i)))
        {
            result = result + (char)tolower(s.at(i));
        }
        else
        {
            result = result + (char)toupper(s.at(i));
        }
    }
    cout << result;
    return 0;
}