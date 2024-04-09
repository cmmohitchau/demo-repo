#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

vector<list < pair < int , int > > > graph;
int V;

void addEdge(int src , int dest , int wt , bool bidir = true)
{
    graph[src].push_back(make_pair(dest,wt));

    if(bidir) graph[dest].push_back(make_pair(src,wt));
}

void dijkstra(vector<int > &dist , int src , int dest)
{
    priority_queue<pair<int , int > , vector<pair<int,int > > , greater<pair<int , int > > > pq;

    for(int i = 0 ; i < dist.size() ; i++)
    {
        dist[i] = 1e9;
    }
    vector<int > track;
    dist[src] = 0;
    pq.push(make_pair(src,0));

    while(!pq.empty())
    {
        int node = pq.top().first;
        int dis = pq.top().second;
        pq.pop();
        

        for(auto it : graph[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push(make_pair(adjNode,dist[adjNode]));
            }

        }

    }

    for(int i = 0 ; i < dist.size() ; i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n The shortest distance between source and destination is : " << dist[dest] << "through " ;
    for(int i : track)
    {
        cout << i << "->";
    }

}

int main()
{
    cout << "Enter the number of vertices : ";
    cin >> V;

    graph.resize(V,list<pair<int , int > > ());
    int e;
    cout << "Enter number of edges : ";
    cin >> e;

    while(e--)
    {
        int s , d, wt;
        cin >> s >> d >> wt;
        addEdge(s,d,wt);
    }
    vector<int > dist(V);
    dijkstra(dist,0,5);


    return 0;
}



