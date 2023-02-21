#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

// structure of node
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
int size(Node *node)
{
    // write your code here
    int sizebt = 0;
    if (node == NULL)
    {
        return 0;
    }
    int ls = size(node->left);
    int rs = size(node->right);

    sizebt = ls + rs + 1;

    return sizebt;
}

int height(Node *node)
{
    // write your code here
    int h = -1;
    if (node == NULL)
    {
        return 0;
    }
    int lh = height(node->left);
    int rh = height(node->right);

    h = max(h, max(lh, rh));
    h++;
    return h;
}

int maximum(Node *node)
{
    // write your code here
    // bst works as the rightmost element is the largest
    // uisng that

    if (node->right != NULL)
    {
        maximum(node->right);
    }
    else
    {
        return node->data;
    }
}

int sum(Node *root)
{

    // write your code here
    if (root == NULL)
    {
        return 0;
    }
    int lsum = sum(root->left);
    int rsum = sum(root->right);

    return lsum + rsum + root->data;
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

    Node *root = constructTree(arr);

    int sz = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout << sz << endl;
    cout << sm << endl;
    cout << max << endl;
    cout << ht << endl;
}