#include <bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int> &num)
{

    // write your code here
    unordered_map<int, bool> hmap;

    // loop1 to put true
    for (int val : num)
    {
        hmap.insert({val, true});
    }

    // loop 2 to put false if a predecessor element is found
    for (int val : num)
    {
        if (hmap.count(val - 1))
        {
            hmap[val] = false;
        }
    }

    // loop 3 the logic

    int maxLen = 0;
    int maxKey;
    for (int val : num)
    {
        if (hmap[val] == true)
        {
            int sl = 1;
            int skey = val;
            while (hmap.count(val + sl))
            {
                sl++;
            }
            // checking for maxLen
            if (sl > maxLen)
            {
                maxKey = val;
                maxLen = sl;
            }
        }
    }

    // output
    for (int i = 0; i < maxLen; i++)
    {
        cout << maxKey + i << endl;
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    longestConsecutive(arr);

    return 0;
}