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

void hasPath(vector<Edge> graph[], int src, int dest, bool visited[], string psf)
{
    // base case
    if (src == dest)
    {
        psf += to_string(src);
        cout << psf << endl;
    }
    // marking visited
    visited[src] = true;

    // adding the current vertice
    psf += to_string(src);
    //
    for (Edge edge : graph[src])
    {
        if (!visited[edge.nbr]) // visited[edge.nbr]==false not working
        {
            hasPath(graph, edge.nbr, dest, visited, psf);
        }
    }
    visited[src] = false;
    return;
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

    int src;
    cin >> src;
    int dest;
    cin >> dest;
    // write your code here
    bool visited[vtces];
    string psf = "";
    hasPath(graph, src, dest, visited, psf);
}