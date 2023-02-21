#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair
{
public:
    Node *node = nullptr;
    int state = 0;

    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

// Display function
void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

// Height function
int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

class balTree
{
public:
    int bt;
    int ht;
};

balTree isbalanceHelper(Node *node)
{
    // base case
    if (node == NULL)
    {
        balTree b;
        b.bt = 1;
        b.ht = 0;
        return b;
    }

    // traversal
    balTree l = isbalanceHelper(node->left);
    balTree r = isbalanceHelper(node->right);

    balTree ans;
    // conditions
    if (abs(l.ht - r.ht > 1) || (l.bt == 0 || r.bt == 0))
    {
        ans.bt = 0;
        return ans;
    }

    //
    ans.bt = 1;
    ans.ht = max(l.ht, r.ht) + 1;
    return ans;
}

int isbalance(Node *node)
{
    // write your code here
    balTree ans;
    ans = isbalanceHelper(node);
    return ans.bt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(tmp);
        }
    }

    Node *root = constructTree(arr);

    int r = isbalance(root);
    if (r == 1)
        cout << "true";
    else
        cout << "false";
}