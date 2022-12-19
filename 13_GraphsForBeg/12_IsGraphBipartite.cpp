#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
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

class Pair
{
public:
    int src;

    Pair(int src)
    {
        this->src = src;
    }
};

bool isBipartite(vector<vector<Edge>> graph, int src, int visited[], int level)
{
    // remove mark work add
    queue<Pair> q;

    // adding the first pair
    Pair *p = new Pair(src);
    q.push(*p);

    // loop
    while (!q.empty())
    {
        // remove
        Pair r = q.front();
        q.pop();

        // mark
        if (visited[r.src] != -1)
        {
            // since the graph is cyclic, check for even length cycle
            //  if the psf string is of odd length, it is of even length
            //  since, for even length of edges, the vertices are odd
            if (visited[r.src] == level + 1)
            {
                // even cycle
                return true;
            }
            else
            {
                // odd cycle
                return false;
            }
        }
        level++;
        visited[r.src] = level;

        // loop
        for (Edge e : graph[r.src])
        {
            if (visited[e.nbr] == -1)
            {
                Pair *p1 = new Pair(e.nbr);
                q.push(*p1);
            }
        }
    }
    // the graph here is not cyclic
    return true;
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
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v));
        graph[v].push_back(Edge(v, u));
    }

    // write your code here
    // 1. If the graph is acyclic, it is bipartite
    // 2. If the graph is of even length cycle, it is bipartite

    // visited[vtces]={-1} will only set the first element to -1 not all
    int visited[vtces];
    // using the fill fucntion from algorithm
    fill(visited, visited + vtces, -1);

    // loop
    bool b;
    for (int i = 0; i < vtces; i++)
    {
        if (visited[i] == -1)
        {
            // go all in boi
            b = isBipartite(graph, i, visited, -1);
        }
    }
    if (b == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}