#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair
{
    Node *node = nullptr;
    int state = 0;

    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
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

bool find(Node *node, int data)
{
    if (node == NULL)
    {
        return false;
    }
    if (data < node->data)
    {
        find(node->left, data);
    }
    else if (data > node->data)
    {
        find(node->right, data);
    }
    else
    {
        return true;
    }
}

void travelAndPrint(Node *root, Node *node, int tar)
{

    // write your code here
    if (node == NULL)
    {
        return;
    }

    travelAndPrint(root, node->left, tar);
    // inorder
    int com = tar - node->data;

    if (com > node->data)
    {
        if (find(root, com))
        {
            cout << node->data << " " << com << endl;
        }
    }

    travelAndPrint(root, node->right, tar);

    // // cant understant how to remove duplicacies
    // // Approach
    // // Brute force
    // // for each node, traverse and add all nodes to see if it fits the target
    // // avoid duplicacies - can use stack or queue
    // // can use property of bst, to traverse left or right
    // //
    // // base case
    // if (node == NULL || root == NULL)
    // {
    //     return;
    // }
    // // printing
    // if (node->data + root->data == tar)
    // {
    //     cout << node->data << " " << root->data << endl;
    // }
    // // inorder
    // travelAndPrint(root, node->left, tar);
    // //
    // // traversal keeping the node stiff

    // if (tar < root->data + node->data)
    // {
    //     travelAndPrint(root->left, node, tar);
    // }
    // else
    // {
    //     travelAndPrint(root->right, node, tar);
    // }

    // travelAndPrint(root, node->right, tar);
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

    int k1;
    cin >> k1;

    Node *root = construct(arr);
    travelAndPrint(root, root, k1);
}