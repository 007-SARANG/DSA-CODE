#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    int ans = -1;
    for (int x : a) {
        if (mp[x] == 1) {
            ans = x;
            break;
        }
    }
    if (ans == -1) cout << "None";
    else cout << ans;
    return 0;
}
