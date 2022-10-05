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

int min(Node *node)
{
    //     Write your code here
    // base case
    if (node->left == NULL)
    {
        return node->data;
    }
    // recursion
    int ans = min(node->left);
    return ans;
}

int max(Node *node)
{
    //     Write your code here
    //
    if (node->right == NULL)
    {
        return node->data;
    }

    //
    int ans = max(node->right);
}

int sum(Node *node)
{

    //     Write your code here
    // base case
    if (node == NULL)
    {
        return NULL;
    }
    int ans;
    int lt = sum(node->left);
    int rt = sum(node->right);

    ans = lt + rt + node->data;
    return ans;
}

int size(Node *node)
{

    //     Write your code here
    //
    if (node == NULL)
    {
        return NULL;
    }

    //
    int lsize = size(node->left);
    int rsize = size(node->right);

    return lsize + rsize + 1;
}

bool find(Node *node, int data)
{

    //     Write your code here
    //
    if (node == NULL)
    {
        return NULL;
    }
    //
    if (node->data == data)
    {
        return true;
    }
    //
    bool ans;
    if (data < node->data)
    {
        ans = find(node->left, data);
    }
    else
    {
        ans = find(node->right, data);
    }

    return ans;
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
    int data;
    cin >> data;
    Node *root = construct(arr);
    cout << size(root) << "\n"
         << sum(root) << "\n"
         << max(root) << "\n"
         << min(root) << "\n";
    if (find(root, data))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}