#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];
    unordered_set<int> s(A.begin(), A.end());
    vector<int> ans;
    for (int x : B) {
        if (s.count(x)) {
            ans.push_back(x);
            s.erase(x);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    return 0;
}
