#include <iostream>
#include <vector>
#include <string>

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
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

// inefficient code coz diameter is a recursive fn and it calls upon height function
// which is also a recursive fn
int diameter(Node *root)
{
    // write your code here
    // base case
    if (root == NULL)
        return NULL;

    // Approach finding the max diameter in left tree, right tree
    //  and if left and right tree combined passing through root

    // max diameter in left tree
    int lh = diameter(root->left);
    // max diameter in right tree
    int rh = diameter(root->right);
    // in both tree combining root
    int rootD = height(root->left) + height(root->right) + 2;

    int dia = max(rootD, max(lh, rh));

    return dia;
}

class DiaPair
{
public:
    int ht;
    int dia;
};

DiaPair diameter1(Node *node)
{
    if (node == NULL)
    {
        DiaPair p;
        p.ht = -1;
        p.dia = 0;
        return p;
    }
    DiaPair lp = diameter1(node->left);
    DiaPair rp = diameter1(node->right);

    DiaPair mp;
    mp.ht = max(lp.ht, rp.ht) +1;
    mp.dia = max(lp.ht + rp.ht + 2, max(lp.ht, rp.ht));

    return mp;
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

    // in the name of efficiency

    // int dia = 0;
    // dia = diameter(root);
    // cout << dia;

    DiaPair ans = diameter1(root);
    cout << ans.dia << endl;
    return 0;
}