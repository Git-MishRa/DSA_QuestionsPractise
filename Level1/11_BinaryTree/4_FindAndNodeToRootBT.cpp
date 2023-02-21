#include <iostream>
#include <string>
#include <vector>

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

vector<int> nodeToRoot;
bool find(Node *node, int data)
{
    // write your code here
    if (node == NULL)
    {
        return false;
    }

    if (node->data == data)
    {
        nodeToRoot.push_back(node->data);
        return true;
    }
    bool flc = find(node->left, data);
    if (flc)
    {
        nodeToRoot.push_back(node->data);
        return true;
    }
    bool frc = find(node->right, data);
    if (frc)
    {
        nodeToRoot.push_back(node->data);
        return true;
    }
    return false;
}

vector<int> nodeToRootPath(Node *node, int data)
{

    // find(node, data);
    return nodeToRoot;

    // write your code here
    // base case end of constructTree
    // if (node == NULL)
    // {
    //     vector<int> empt;
    //     return empt;
    // }
    // if (node->data == data)
    // {
    //     vector<int> v;
    //     v.push_back(node->data);
    //     return v;
    // }

    // // i failed to understand how to transmit data returning recursion
    // vector<int> lpathChild = nodeToRootPath(node->left, data);
    // if (lpathChild.size() > 0)
    // {
    //     lpathChild.push_back(node->data);
    //     return lpathChild;
    // }
    // vector<int> rpathChild = nodeToRootPath(node->right, data);
    // if (rpathChild.size() > 0)
    // {
    //     rpathChild.push_back(node->data);
    //     return rpathChild;
    // }

    // vector<int> empt;
    // return empt;
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
    int data;
    cin >> data;
    bool found = find(root, data);
    found == 1 ? cout << "true" << endl : cout << "false" << endl;
    vector<int> path = nodeToRootPath(root, data);
    cout << "[";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}