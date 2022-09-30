#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
public:
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

void iterativePrePostInTraversal(Node *node)
{
    // write your code here
    Pair *p = new Pair(node, 1);

    // stack
    stack<Pair> st;
    st.push(*p);

    // empty answer strings
    string pre = "";
    string post = "";
    string inorder = "";

    //
    while (!st.empty())
    {
        Pair top = st.top();

        if (top.state == 1)
        {
            pre += top.node->data + " ";
            top.state++;
            if (top.node->left != NULL)
            {
                Pair *p1 = new Pair(top.node->left, 1);
                st.push(*p1);
            }
        }
        else if (top.state == 2)
        {
            inorder += top.node->data + " ";
            top.state++;
            if (top.node->right != NULL)
            {
                Pair *p2 = new Pair(top.node->right, 1);
                st.push(*p2);
            }
        }
        else
        {
            post += top.node->data + " ";
            st.pop();
        }
    }
    cout << pre << endl;
    cout << inorder << endl;
    cout << post;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(temp);
        }
    }
    Node *root = construct(arr);
    iterativePrePostInTraversal(root);
}