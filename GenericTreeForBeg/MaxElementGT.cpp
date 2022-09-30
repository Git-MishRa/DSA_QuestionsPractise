#include <bits/stdc++.h>
#include <iostream>

using namespace std;
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

int max1Helper(Node *node, Node *maxed)
{
    if (node->data > maxed->data)
    {
        maxed->data = node->data;
    }
    for (Node *child : node->children)
    {
        max1Helper(child, maxed);
    }
    return maxed->data;
}

int max1(Node *node)
{
    // write your code here
    Node *maxed = new Node;
    maxed->data = INT_MIN;
    int max = max1Helper(node, maxed);
    return max;
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

    Node *root = construct(arr, n);
    int maximum = max1(root);

    cout << maximum << endl;
}