#include <bits/stdc++.h>
#include <queue>
#include <stack>
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
void levelorder(Node *node)
{
    // write your code here
    stack<Node *> ms;
    ms.push(node);

    stack<Node *> cs;
    int level = 1;
    while (ms.size() > 0)
    {
        node = ms.top();
        ms.pop();
        cout << node->data << " ";
        if (level % 2 == 1)
        {
            for (int i = 0; i < node->children.size(); i++)
            {
                Node *child = node->children.at(i);
                cs.push(child);
            }
        }
        else
        {
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                Node *child = node->children.at(i);
                cs.push(child);
            }
        }
        if (ms.size() == 0)
        {
            ms = cs;
            stack<Node *> temp;
            cs = temp;
            level++;
            cout << endl;
        }
    }
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
    levelorder(root);
}