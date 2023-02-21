#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

// using the reference variable to transcend [visited,ans] irrespective of recursion stack
void topoSort(vector<vector<Edge>> graph, vector<bool> &visited, int src, stack<int> &ans)
{
    // work to be done in post order
    // base case
    if (visited[src] == true)
    {
        return;
    }

    visited[src] = true;

    // loop
    for (Edge e : graph[src])
    {
        if (visited[e.nbr] == false)
        {
            topoSort(graph, visited, e.nbr, ans);
        }
    }
    // postorder i.e work here
    // store it because in topological sort, we print it backwards
    // not my idea for sure
    ans.push(src);
    return;
}

int main()
{

    int vtces;
    cin >> vtces;
    vector<vector<Edge>> graph(vtces, vector<Edge>());

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(Edge(u, v));
    }

    // write your code here
    // topological sorting
    // use DFS as the vertex with no unvisited neighbour is the independent work to be done
    // use loop so that you will cover each vertex
    // as some of them might be left out due to directed paths

    // data structures
    vector<bool> visited(vtces, false);
    stack<int> ans;

    // loop
    for (int i = 0; i < vtces; i++)
    {
        if (visited[i] == false)
        {
            topoSort(graph, visited, i, ans);
        }
    }

    // printing process here
    while (!ans.empty())
    {
        int x = ans.top();
        ans.pop();
        cout << x << endl;
    }

    return 0;
}