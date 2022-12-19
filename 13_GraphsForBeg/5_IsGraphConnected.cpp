#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void connected(vector<Edge> graph[], bool visited[], vector<int> &comp, int src)
{
    visited[src] = true;
    comp.push_back(src);
    for (Edge e : graph[src])
    {
        if (!visited[e.nbr])
        {
            connected(graph, visited, comp, e.nbr);
        }
    }
}

int main()
{
    int vtces;
    cin >> vtces;
    vector<Edge> graph[vtces];

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1;
        int v2;
        int wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    vector<vector<int>> comps;

    // write your code here
    bool visited[vtces];
    for (int i = 0; i < vtces; i++)
    {
        if (!visited[i])
        {
            vector<int> comp;
            connected(graph, visited, comp, i);
            comps.push_back(comp);
        }
    }

    comps.size() == 1 ? cout << "true" : cout << "false";
    return 0;
}