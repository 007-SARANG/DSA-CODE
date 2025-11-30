#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU{
    vector<int> parent, rankv;

    DSU(int n){
        parent.resize(n);
        rankv.assign(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a); b = find(b);
        if(a != b){
            if(rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if(rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

int main(){
    vector<vector<int>> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    int n = 4;

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a[2] < b[2];
    });

    DSU dsu(n);
    int mst = 0;

    for(auto &e : edges){
        if(dsu.find(e[0]) != dsu.find(e[1])){
            mst += e[2];
            dsu.unite(e[0], e[1]);
        }
    }

    cout << mst;
}
