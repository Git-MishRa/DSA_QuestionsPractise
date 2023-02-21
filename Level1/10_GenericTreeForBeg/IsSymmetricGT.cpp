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

bool areSimilar(Node *n1, Node *n2)
{

    // Write your code here
    // approach check for same number of children
    bool res;
    if (n1->children.size() != n2->children.size())
    {
        return false;
    }
    else if (n1->children.size() == 0 && n2->children.size() == 0)
    {
        return true;
    }
    for (int i = 0; i < n1->children.size(); i++)
    {
        res = areSimilar(n1->children[i], n2->children[i]);
    }

    return res;

    // if (sizeRec(n1) != sizeRec(n2) || height(n1) != height(n2))
    // {
    //     return false;
    // }
    // else
    // {
    //     n1->children.size() == n2->children.size();
    // }
}

bool issym(Node *node)
{
    // Write your code here
    // bool res;

    // Check the first and last child for similarity
    // keep going for second and second last and so on
    for (int i = 0; i <= node->children.size() / 2; i++)
    {
        if (!areSimilar(node->children[i], node->children[node->children.size() - 1 - i]))
        {
            return false;
        }
    }
    return true;
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
    bool sym = issym(root);
    if (sym == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}