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
    string path;

    Pair(int src, string path)
    {
        this->src = src;
        this->path = path;
    }
};

main()
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

    int src;
    cin >> src;
    // write your code here
    // remove mark work add
    queue<Pair> q;
    bool visited[vtces] = {false};

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
            continue;
        }
        visited[r.src] = true;

        // print / work
        cout << r.src << "@" << r.path << endl;

        // loop
        for (Edge e : graph[r.src])
        {
            if (visited[e.nbr] == false)
            {
                Pair *p1 = new Pair(e.nbr, r.path + to_string(e.nbr));
                q.push(*p1);
            }
        }
    }

    return 0;
}