#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) { val = x; left = right = NULL; }
};

Node* build(vector<int> &a) {
    if (a.empty() || a[0] == -1) return NULL;
    int n = a.size();
    vector<Node*> nodes(n, NULL);
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) nodes[i] = new Node(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

bool dfs(Node* root, unordered_set<int> &st) {
    if (!root) return false;
    if (st.count(root->val)) return true;
    st.insert(root->val);
    if (dfs(root->left, st)) return true;
    if (dfs(root->right, st)) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Node* root = build(a);
    unordered_set<int> st;
    bool dup = dfs(root, st);
    if (dup) cout << "Duplicates Found";
    else cout << "No Duplicates";
    return 0;
}
