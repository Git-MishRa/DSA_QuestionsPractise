#include <iostream>
#include <vector>
#include <stack>
#include <string>
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
    string psf;

    Pair(int src, string psf)
    {
        this->src = src;
        this->psf = psf;
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
    int src;
    cin >> src;
    // write your code here
    // replacing stack with queue in BFS will lead to DFS
    // for more clarification see https://youtu.be/iUtmQ66IC_0

    // data structures
    vector<bool> visited(vtces, false);
    stack<Pair> st;

    // first pair
    Pair *fpair = new Pair(src, to_string(src));
    st.push(*fpair);

    // loop
    while (!st.empty())
    {
        // remove
        Pair rem = st.top();
        st.pop();

        // mark *
        if (visited[rem.src] == true)
        {
            continue;
        }
        visited[rem.src] = true;

        // work
        cout << rem.src << "@" << rem.psf << endl;

        // add *
        for (Edge e : graph[rem.src])
        {
            if (visited[e.nbr] == false)
            {
                Pair *np = new Pair(e.nbr, rem.psf + to_string(e.nbr));
                st.push(*np);
            }
        }
    }

    return 0;
}