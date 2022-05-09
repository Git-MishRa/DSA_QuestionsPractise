#include <iostream>
#include <string>
using namespace std;

int main()
{ // Permutations of a string
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (i != j)
            {
                cout << str.at(i) << str.at(j) << endl;
            }
            else
            {
                cout << str.at(i) << endl;
            }
        }
    }
    return 0;
}