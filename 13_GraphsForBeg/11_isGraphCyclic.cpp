#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    string psf;

    Pair(int src, string psf)
    {
        this->src = src;
        this->psf = psf;
    }
};

bool isCycle(vector<vector<Edge>> graph, int src, bool visited[])
{
    // remove mark work add
    queue<Pair> q;

    // adding the first pair
    Pair *p = new Pair(src, to_string(src));
    q.push(*p);

    // loop
    while (!q.empty())
    {
        // remove
        Pair r = q.front();
        q.pop();

        // mark
        if (visited[r.src])
        {
            return true;
        }
        visited[r.src] = true;

        // loop
        for (Edge e : graph[r.src])
        {
            if (visited[e.nbr] == false)
            {
                Pair *p1 = new Pair(e.nbr, r.psf + to_string(e.nbr));
                q.push(*p1);
            }
        }
    }
    return false;
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
    bool visited[vtces] = {false};

    // loop
    for (int i = 0; i < vtces; i++)
    {
        if (visited[i] == false)
        {
            // go all in boi
            bool iscycle = isCycle(graph, i, visited);
            if (iscycle)
            {
                cout << "true";
                return 0;
            }
        }
    }
    cout<<"false";
    return 0;
}