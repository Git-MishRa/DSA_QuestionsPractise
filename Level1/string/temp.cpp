#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    // cout << s.length();
    string ans;
    int count = 1;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        // cout << "he";
        while (i + 1 < s.length() && (c == s.at(i + 1)))
        {
            // cout << "he2";
            count++;
            i++;
        }
        if (count != 0)
        {
            ans += c + to_string(count);
        }
        else
        {
            ans += c;
        }
        count = 1;
    }
    cout << ans;
    return 0;
}