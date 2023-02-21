#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;
    int wt = 0;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Pair
{
public:
    int src;
    int psrc;
    int wt;

    Pair(int src, int psrc, int wt)
    {
        this->src = src;
        this->psrc = psrc;
        this->wt = wt;
    }
};

class compare
{
public:
    bool operator()(Pair const &p1, Pair const &p2)
    {
        return p1.wt > p2.wt;
    }
};

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

        graph[u].push_back(Edge(u, v, w));
        graph[v].push_back(Edge(v, u, w));
    }

    // write your code here
    // Prim's algorithm
    // select a vertex and find all paths
    // if a smaller path is find, update it

    // data structures
    vector<bool> visited(vtces, false);
    priority_queue<Pair, vector<Pair>, compare> q;

    // loop for BFS
    Pair *pfirst = new Pair(graph[0][0].src, -1, 0);
    q.push(*pfirst);

    // loop
    while (!q.empty())
    {
        // remove
        Pair rem = q.top();
        q.pop();
        // mark *
        if (visited[rem.src] == true)
        {
            continue;
        }
        visited[rem.src] = true;
        // work
        if (rem.psrc != -1)
        {
            cout << "[" << rem.src << "-" << rem.psrc << "@" << rem.wt << "]" << endl;
        }

        // add *
        for (Edge e : graph[rem.src])
        {
            if (visited[e.nbr] == false)
            {
                Pair *p = new Pair(e.nbr, rem.src, e.wt);
                q.push(*p);
            }
        }
    }

    return 0;
}