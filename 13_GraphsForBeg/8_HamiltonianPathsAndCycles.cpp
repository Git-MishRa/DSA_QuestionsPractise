#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

void hamiltonian(vector<Edge> graph[], int src, int dest, bool visited[], string path, int count, int vtces)
{
    // base
    if (count == vtces)
    {
        path += to_string(src);
        int key = 0;
        for (Edge ed : graph[src])
        {
            if (ed.nbr == dest)
            {
                key++;
                cout << path << "*" << endl;
            }
        }
        if (key == 0)
        {
            cout << path << "." << endl;
        }
        return;
    }

    // mark visited
    visited[src] = true;

    // add path
    path += to_string(src);

    // loop for nbrs
    for (Edge e : graph[src])
    {
        if (!visited[e.nbr])
        {
            hamiltonian(graph, e.nbr, dest, visited, path, count + 1, vtces);
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
        graph[v1].push_back(Edge(v1, v2));
        graph[v2].push_back(Edge(v2, v1));
    }

    int src;
    cin >> src;

    // write your code here

    bool visited[vtces] = {false};
    string path = "";
    hamiltonian(graph, src, src, visited, path, 1, vtces);

    return 0;
}