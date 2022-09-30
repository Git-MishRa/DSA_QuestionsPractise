#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Node
{
public:
    int data = 0;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};

void display(Node *node)
{
    string s = "";
    s += to_string(node->data) + " Child: ";
    for (Node *child : node->children)
    {
        s += to_string(child->data) + ", ";
    }

    cout << s << "." << endl;

    for (Node *child : node->children)
    {
        display(child);
    }
}

Node *constructor01(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;

    vector<Node *> stack;
    stack.push_back(new Node(arr[0]));

    Node *root = stack[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != -1)
        {
            Node *node = stack.back();
            Node *nnode = new Node(arr[i]);

            node->children.push_back(nnode);
            stack.push_back(nnode);
        }
        else
            stack.pop_back();
    }
    return root;
}

vector<int> *rootNodeToPath(Node *node, int data)
{

    if (node->data == data)
    {
        vector<int> *base = new vector<int>();
        base->push_back(data);
        return base;
    }

    vector<int> *ans = new vector<int>();
    for (Node *child : node->children)
    {
        vector<int> *recAns = rootNodeToPath(child, data);
        if (recAns->size() > 0)
        {
            recAns->push_back(node->data);
            return recAns;
        }
    }
    return ans;
}

int lca(Node *node, int data1, int data2)
{
    vector<int> onePath = *rootNodeToPath(node, data1);
    vector<int> twoPath = *rootNodeToPath(node, data2);

    int i = onePath.size() - 1;
    int j = twoPath.size() - 1;
    bool flag = false;
    while (i >= 0 && j >= 0 && onePath[i] == twoPath[j])
    {
        flag = true;
        i--;
        j--;
    }

    int ans = 0;
    if (flag)
    {
        ans = onePath[i++];
    }
    return ans;
}

int distance(Node *node, int data1, int data2)
{
    // Write your code here
    // 1 find the first common ancestor
    // 2 calculate the edges for both of them
    // add them up

    // finding lca and updating the edge too
    vector<int> route1;
    route1 = *rootNodeToPath(node, data1);
    vector<int> route2;
    route2 = *rootNodeToPath(node, data2);

    int i = 1;
    int edge1, edge2;
    int res = 0;
    while (route1[route1.size() - i] == route2[route2.size() - i])
    {
        res = route1[route1.size() - i];
        i++;
    }
    edge1 = route1.size() - i;
    edge2 = route2.size() - i;

    // result i.e distance
    // since we are starting from i=1 instead of i=0 for both edges
    // add 2
    int dis = edge1 + edge2 + 2;
    return dis;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int data1;
    cin >> data1;
    int data2;
    cin >> data2;

    Node *root = constructor01(arr);
    int dist = distance(root, data1, data2);
    cout << dist << endl;
}

int main()
{
    solve();
    return 0;
}