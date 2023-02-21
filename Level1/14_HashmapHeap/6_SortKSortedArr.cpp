#include <bits/stdc++.h>
using namespace std;

int sortK(int arr[], int n, int k)
{
    // write your code here
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    // output
    for (int i = 0; i < n; i++)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr[i] = data;
    }
    int k;
    cin >> k;
    sortK(arr, n, k);
    return 0;
}