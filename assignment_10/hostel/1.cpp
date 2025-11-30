#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_set<int> s;
    bool dup = false;
    for (int x : a) {
        if (s.count(x)) {
            dup = true;
            break;
        }
        s.insert(x);
    }
    if (dup) cout << "true";
    else cout << "false";
    return 0;
}
