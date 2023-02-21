#include <iostream>
#include <vector>
#include <string>
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
    string psf;
    int wsf;

    Pair(int src, string psf, int wsf)
    {
        this->src = src;
        this->psf = psf;
        this->wsf = wsf;
    }
};

// struct CompareHeight {
//     bool operator()(Person const& p1, Person const& p2)
//     {
//         // return "true" if "p1" is ordered
//         // before "p2", for example:
//         return p1.height < p2.height;
//     }
// };
class compare
{
public:
    bool operator()(Pair const &p1, Pair const &p2)
    {
        return p1.wsf > p2.wsf;
    }
};

// The answers on Noados is inconsistence with the algorithm

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
    // store values for each vertex from the src, update the psf and weight if smaller weight is found
    // BFS with minimum priority queue

    // required data structures
    vector<bool> visited(vtces, false);

    // custom priority queue with compare class operator overload
    priority_queue<Pair, vector<Pair>, compare> q;

    // BFS
    Pair *p = new Pair(src, to_string(src), 0);
    q.push(*p);

    // loop
    while (!q.empty())
    {
        // remove
        Pair r = q.top();
        q.pop();

        // mark
        if (visited[r.src])
        {
            continue;
        }
        visited[r.src] = true;

        // print / work
        cout << r.src << " via " << r.psf << " @ " << r.wsf << endl;

        // loop or add
        for (Edge e : graph[r.src])
        {
            if (visited[e.nbr] == false)
            {
                Pair *p1 = new Pair(e.nbr, r.psf + to_string(e.nbr), r.wsf + e.wt);
                q.push(*p1);
            }
        }
    }

    return 0;
}