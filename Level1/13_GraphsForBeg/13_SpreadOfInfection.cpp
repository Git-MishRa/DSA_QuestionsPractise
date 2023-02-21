#include <iostream>
#include <vector>
#include <queue>

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
    int level;

    Pair(int src, int level)
    {
        this->src = src;
        this->level = level;
    }
};

void spreadOfInfection(vector<vector<Edge>> graph, vector<int> visited, int src, int t)
{
    //
    int infectedCount = 0;

    // queue
    queue<Pair> q;
    Pair *p1 = new Pair(src, 1);
    q.push(*p1);

    // loop
    while (!q.empty())
    {
        Pair rem = q.front();
        q.pop();

        // marking
        // if (visited[rem.src != -1])
        // {
        //     continue;
        // }
        if (rem.level > t)
        {
            cout << infectedCount << endl;
            return;
        }
        else
        {
            // remember not to repeat the elements of queue
            // as we are pushing duplicate elements into the queue
            if (visited[rem.src] != -1)
            {
                continue;
            }
            visited[rem.src] = rem.level;
            infectedCount++;
        }

        for (Edge e : graph[rem.src])
        {
            if (visited[e.nbr] == -1)
            {
                Pair *ad = new Pair(e.nbr, rem.level + 1);
                q.push(*ad);
            }
        }
    }
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
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v));
        graph[v].push_back(Edge(v, u));
    }
    int src, t;
    cin >> src;
    cin >> t;

    // write your code here
    // Application of BFS
    // as per the question, start at the src with time=1 consumed

    // visited
    vector<int> visited(vtces, -1);

    // BFS for a particular source
    spreadOfInfection(graph, visited, src, t);

    return 0;
}