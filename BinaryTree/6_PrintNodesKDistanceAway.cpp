#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
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
    Node *node = new Node(arr[idx++], nullptr, nullptr);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

vector<Node *> nodeToRootPath(Node *node, int data)
{
    vector<Node *> temp;
    if (node == nullptr)
    {
        return temp;
    }

    vector<Node *> ans;
    if (node->data == data)
    {
        ans.push_back(node);
        return ans;
    }
    vector<Node *> left = nodeToRootPath(node->left, data);
    if (left.size() > 0)
    {
        left.push_back(node);
        return left;
    }
    vector<Node *> right = nodeToRootPath(node->right, data);
    if (right.size() > 0)
    {
        right.push_back(node);
        return right;
    }
    return temp;
}

vector<Node *> nodeToRoot;
bool find(Node *node, int data)
{
    // write your code here
    if (node == NULL)
    {
        return false;
    }

    if (node->data == data)
    {
        nodeToRoot.push_back(node);
        return true;
    }
    bool flc = find(node->left, data);
    if (flc)
    {
        nodeToRoot.push_back(node);
        return true;
    }
    bool frc = find(node->right, data);
    if (frc)
    {
        nodeToRoot.push_back(node);
        return true;
    }
    return false;
}

void printKLevelsDown(Node *node, int k, Node *block)
{
    if (node == nullptr || k < 0 || node == block)
        return;

    if (k == 0)
    {
        cout << node->data << endl;
    }

    printKLevelsDown(node->left, k - 1, block);
    printKLevelsDown(node->right, k - 1, block);
}

void printKNodesFar(Node *node, int data, int k)
{
    // write your code here
    // missed the concept of block
    // node k level down which exist in the same tree as base node should be taken care of
    find(node, data);
    for (int i = 0; i < nodeToRoot.size(); i++)
    {

        printKLevelsDown(nodeToRoot[i], k - i, i == 0 ? NULL : nodeToRoot[i - 1]);
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;
        if (inp != "n")
        {
            arr.push_back(stoi(inp));
        }
        else
        {
            arr.push_back(-1);
        }
    }

    int data;
    cin >> data;
    int k;
    cin >> k;
    Node *root = constructTree(arr);
    printKNodesFar(root, data, k);

    return 0;
}