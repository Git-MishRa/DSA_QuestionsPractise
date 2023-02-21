// 1. visit till last node
// 2. return the sum of that tree, since no child, sum=node->data
// 3. now add the returned summ with the current node->data

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int c = INT_MAX;
int flloor = INT_MIN;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

Node *construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = newNode(arr[i]);

            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

int msum = 0;
int msumnode = 0;

int subsumtree(Node *node)
{
    // Write your code here
    int childsum = node->data;
    if (node->children.size() == 0)
    {
        if (node->data > msum)
        {
            msumnode = node->data;
            msum = node->data;
        }
        return node->data;
    }

    // recursion
    for (Node *child : node->children)
    {
        childsum += subsumtree(child);
    }

    // swap
    if (msum < childsum)
    {
        msum = childsum;
        msumnode = node->data;
    }
    return childsum;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Node *root = construct(arr, n);
    subsumtree(root);
    cout << msumnode << "@" << msum << endl;
}