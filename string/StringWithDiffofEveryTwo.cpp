//  print string with diffrence of ascii values of the chars imbedded in the string

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, result, s;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (i == input.length() - 1)
        {
            result = result + input.at(i);
        }
        else
        { // to_string function is necessary, type casting will convert to the respective char
            s = to_string((int)input.at(i + 1) - (int)input.at(i));
            result = result + input.at(i) + s;
        }
    }
    cout << result;
    return 0;
}