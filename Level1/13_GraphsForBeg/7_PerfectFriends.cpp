#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
    int src;
    int nbr;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
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
    int n;
    cin >> n;

    int k;
    cin >> k;

    // write your code here
    // making the graph with n students
    vector<Edge> graph[n];
    for (int i = 0; i < k; i++)
    {
        vector<Edge> v;
        graph[i] = v;
    }

    // getting the clubs and students in them
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(Edge(a, b));
        graph[b].push_back(Edge(b, a));
    }

    // getting connected components i.e friends in same club
    vector<vector<int>> comps;
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> comp;
            connected(graph, visited, comp, i);
            comps.push_back(comp);
        }
    }

    // perfect friends logic
    // combination of c1 c2 c3
    // c1c2 + c1c3+ c2c3
    int result = 0;
    for (int i = 0; i < comps.size(); i++)
    {
        for (int j = i + 1; j < comps.size(); j++)
        {
            result += comps[i].size() * comps[j].size();
        }
    }

    cout << result;
    return 0;
}