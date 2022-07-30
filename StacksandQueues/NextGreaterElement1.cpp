#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterRight(vector<int> &arr, int ar[])
{
    vector<int> nge;
    int n = arr.size();
    nge.resize(n, 0);
    nge[n - 1] = -1;
    stack<int> st;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

void nextgreater(vector<int> nums, vector<int> query)
{
    // write your code here
    int arr[nums.size()];
    vector<int> vector;
    vector = nextGreaterRight(nums, arr);
    cout << query.size() << endl;
    for (int i = 0; i < query.size(); i++)
    {
        for (int j = 0; j < vector.size(); j++)
        {
            if (query[i] == nums[j])
            {
                cout << vector[j] << endl;
            }
        }
    }
}

int main(int argc, char **argv)
{
    string str;
    getline(cin, str);

    vector<int> query;
    int idx = 0;
    string curr = "";
    while (idx < str.size())
    {
        if (str[idx] == ' ')
        {
            query.push_back(stoi(curr));
            curr = "";
        }
        else
        {
            curr.push_back(str[idx]);
        }
        idx++;
    }
    query.push_back(stoi(curr));

    string str1;
    getline(cin, str1);
    vector<int> nums;
    idx = 0;
    curr = "";
    while (idx < str1.size())
    {
        if (str1[idx] == ' ')
        {
            nums.push_back(stoi(curr));
            curr = "";
        }
        else
        {
            curr.push_back(str1[idx]);
        }
        idx++;
    }
    nums.push_back(stoi(curr));
    nextgreater(nums, query);
    return 0;
}