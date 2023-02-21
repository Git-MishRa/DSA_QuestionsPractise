#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {

        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

int ans;
int lca(Node *root, int a, int b)
{
    //     Write your code here
    // can check where a and b changes path i.e
    // where a is smaller than node and b is greater than node
    // base case
    if (root == NULL)
    {
        return 0;
    }

    if (a < root->data && b < root->data)
    {
        lca(root->left, a, b);
    }
    else if (a > root->data && b > root->data)
    {
        lca(root->right, a, b);
    }
    else if ((a >= root->data && b <= root->data) || (a <= root->data && b >= root->data))
    {
        ans = root->data;
    }
    // still missing the case where a is parent of b or vice versa
    return root->data;

    // first graphically solving the question is working well
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(x);
        }
    }
    int a, b;
    cin >> a >> b;
    Node *root = construct(arr);
    ans = root->data;
    lca(root, a, b);
    cout << ans << endl;
}