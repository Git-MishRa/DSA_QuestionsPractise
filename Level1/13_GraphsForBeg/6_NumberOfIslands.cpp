#include <bits/stdc++.h>

using namespace std;

void drawTree(vector<vector<int>> arr, vector<vector<bool>> &visited, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 1 || visited[i][j]) // check arr==1 and visited in last to prevent over bound
    {
        return;
    }
    visited[i][j] = true;
    drawTree(arr, visited, i - 1, j, n, m);
    drawTree(arr, visited, i, j + 1, n, m);
    drawTree(arr, visited, i, j - 1, n, m);
    drawTree(arr, visited, i + 1, j, n, m);
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }

    // write your code here

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // cout << visited[2][3] << endl;
    // loop
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0 && !visited[i][j])
            {
                drawTree(arr, visited, i, j, n, m);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
