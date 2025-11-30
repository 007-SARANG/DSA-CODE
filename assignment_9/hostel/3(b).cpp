#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0]={{1,2},{3,6}};
    adj[1]={{0,2},{2,3},{3,8},{4,5}};
    adj[2]={{1,3},{4,7}};
    adj[3]={{0,6},{1,8}};
    adj[4]={{1,5},{2,7}};

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    vector<int> vis(n, 0);

    pq.push({0,0});
    int mst = 0;

    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;
        mst += w;

        for(auto &p : adj[u])
            if(!vis[p.first])
                pq.push({p.second, p.first});
    }

    cout << mst;
}
