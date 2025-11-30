#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, const vector<vector<int>>& adj, vector<int>& vis){
    vis[u] = 1;
    cout << u << " ";
    for(int v : adj[u])
        if(!vis[v]) dfsUtil(v, adj, vis);
}

void dfs(int start, const vector<vector<int>>& adj){
    vector<int> vis(adj.size(), 0);
    dfsUtil(start, adj, vis);
}

int main(){
    vector<vector<int>> adj = {{1,2},{0,3},{0,4},{1},{2}};
    dfs(0, adj);
}
