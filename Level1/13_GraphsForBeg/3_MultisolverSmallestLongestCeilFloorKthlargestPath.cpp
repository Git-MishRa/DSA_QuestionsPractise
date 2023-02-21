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

struct myComp
{
    bool operator()(
        pair<int, string> &a,
        pair<int, string> &b)
    {
        return a.first > b.first;
    }
};
string spath;
int spathwt = INT_MAX;
string lpath;
int lpathwt = INT_MIN;
string cpath;
int cpathwt = INT_MAX;
string fpath;
int fpathwt = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> visited, int criteria, int k, string psf, int wsf)
{
    // write your code here
    // base case
    if (src == dest)
    {
        if (wsf < spathwt)
        {
            spathwt = wsf;
            spath = psf;
        }
        if (wsf > lpathwt)
        {
            lpathwt = wsf;
            lpath = psf;
        }
        if (wsf > criteria && wsf < cpathwt)
        {
            cpathwt = wsf;
            cpath = psf;
        }
        if (wsf < criteria && wsf > fpathwt)
        {
            fpathwt = wsf;
            fpath = psf;
        }

        //
        if (pq.size() < k)
        {
            pair<int, string> p1;
            p1.first = wsf;
            p1.second = psf;
            pq.push(p1);
        }
        else
        {
            if (wsf > pq.top().first)
            {
                pq.pop();
                pair<int, string> p2;
                p2.first = wsf;
                p2.second = psf;
                pq.push(p2);
            }
        }

        return;
    }
    // marking visited
    visited[src] = true;

    // adding the current vertice
    // psf += to_string(src);
    // adding weight
    // Edge e = graph[0][src];
    // wsf += e.wt;
    //
    for (Edge edge : graph[src])
    {
        if (!visited[edge.nbr]) // visited[edge.nbr]==false not working
        {
            multisolver(graph, edge.nbr, dest, visited, criteria, k, psf + to_string(edge.nbr), wsf + edge.wt);
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

    int criteria;
    cin >> criteria;
    int k;
    cin >> k;

    vector<bool> visited(vtces, false);
    multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);

    cout << "Smallest Path = " << spath << "@" << spathwt << endl;
    cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
    cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
    cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
    cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;

    return 0;
}