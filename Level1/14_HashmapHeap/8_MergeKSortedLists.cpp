#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedLists(vector<vector<int>> &lists)
{
    vector<int> rv;
    // write your code here
    // priority queue
    priority_queue<int, vector<int>, greater<int>> pq;

    // O(n^2)
    for (int i = 0; i < lists.size(); i++)
    {
        for (int val : lists[i])
        {
            pq.push(val);
        }
    }
    // O(n)
    while (!pq.empty())
    {
        rv.push_back(pq.top());
        pq.pop();
    }
    return rv;
}

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> lists;
    for (int i = 0; i < k; i++)
    {
        vector<int> list;

        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int data;
            cin >> data;
            list.push_back(data);
        }

        lists.push_back(list);
    }

    vector<int> mlist = mergeKSortedLists(lists);
    for (int val : mlist)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}