#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str, result, s;
    int count = 1;
    cin >> str;
    // cout << str.length() << "   ";
    for (int i = 0; i < str.length(); i++)
    {
        if (i == str.length() - 1) // The issue was that the for loop should run till <str.length(), but this caused the issue in
                                   //  the if block where I compared str.at(i) with str.at(i+1) where i+1 is out of range, giving error
        {
            s = to_string(count);
            result = result + str.at(i) + s;
        }
        else if (str.at(i) == str.at(i + 1))
        {
            count++;
            // cout << temp << "   " << count << "   ";
        }
        else
        {
            s = to_string(count);
            // cout << s;
            // cout << str.at(i) << " " << i << endl;
            if (count == 1)
            {
                result = result + str.at(i);
            }
            else
            {
                result = result + str.at(i) + s;
            }
            count = 1;
        }
        // count = 0;
    }
    cout << result;
    return 0;
}