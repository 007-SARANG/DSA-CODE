#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

vector<int> dijkstra(int src, const vector<vector<pair<int,int>>>& adj){
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d != dist[u]) continue;

        for(auto &p : adj[u]){
            int v = p.first, w = p.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0]={{1,4},{2,1}};
    adj[2]={{1,2},{3,5}};
    adj[1]={{3,1}};
    adj[3]={{4,3}};

    vector<int> d = dijkstra(0, adj);
    for(int x : d) cout << x << " ";
}
