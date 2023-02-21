#include <bits/stdc++.h>
#include <queue>
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
    queue<Node *> parent;
    queue<Node *> childq;
    parent.push(node);
    while (parent.size() > 0)
    {
        node = parent.front();
        cout << node->data << " ";
        parent.pop();

        for (Node *child : node->children)
        {
            childq.push(child);
        }
        if (parent.size() == 0)
        {
            cout << endl;
            parent = childq;
            queue<Node *> temp;
            childq = temp;
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