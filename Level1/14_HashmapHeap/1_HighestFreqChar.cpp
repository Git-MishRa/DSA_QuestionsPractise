#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main()
{
    string input;
    cin >> input;

    // hash unordered_map
    unordered_map<char, int> map;
    int max = INT_MIN;
    char key;
    for (int i = 0; i < input.length(); i++)
    {
        char temp = input.at(i);
        if (map.count(temp))
        {
            map[temp]++;
            if (map[temp] > max)
            {
                key = temp;
                max = map[temp];
            }
        }
        else
        {
            map.insert({temp, 1});
        }
    }

    cout << key << endl;
    return 0;
}