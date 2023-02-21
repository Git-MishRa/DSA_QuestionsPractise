#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

class Pair
{
public:
    Node *node;
    int state;
};

void iterativePreAndPostOrder(Node *root)
{
    // write your code here
    stack<Pair> st;
    string pre = "";
    string post = "";

    // initial push

    Pair p;
    p.node = root;
    p.state = -1;
    st.push(p);

    //
    while (st.size() > 0)
    {
        Pair top = st.top();
        if (top.state == -1)
        {
            pre += top.node->data + " ";
            top.state++;
        }
        else if (top.state = top.node->children.size())
        {
            post += top.node->data + " ";
            st.pop();
        }
        else
        {
            Pair cp;
            cp.node = top.node->children[top.state];
            cp.state = -1;
            st.push(cp);
            top.state++;
        }
    }

    cout << pre << endl;
    cout << post << endl;
}

Node *construct(vector<int> &arr)
{
    Node *root = nullptr;

    stack<Node *> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = new Node();
            t->data = arr[i];

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

int main()
{
    int n, x;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    Node *root = construct(arr);
    iterativePreAndPostOrder(root);
}