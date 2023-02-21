#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1;
    int arr1[n1];

    // data structure
    unordered_map<int, int> mp;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
        // if else
        if (mp.count(arr1[i]))
        {
            mp[arr1[i]]++;
        }
        else
        {
            mp.insert({arr1[i], 1});
        }
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];

        // write your code here
        if (mp.count(arr2[i]))
        {
            cout << arr2[i] << endl;
            if (mp[arr2[i]] == 1)
            {
                mp.erase(arr2[i]);
            }
            else
            {

                mp[arr2[i]]--;
            }
        }
    }
    return 0;
}