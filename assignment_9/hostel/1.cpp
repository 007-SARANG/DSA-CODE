#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> vis(n, 0);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        cout << u << " ";

        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    vector<vector<int>> adj = {{1,2},{0,3},{0,4},{1},{2}};
    bfs(0, adj);
}
