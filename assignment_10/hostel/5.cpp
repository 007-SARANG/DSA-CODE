#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) { data = x; next = NULL; }
};

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "false";
        return 0;
    }
    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        nodes.push_back(new Node(x));
        if (i > 0) nodes[i-1]->next = nodes[i];
    }
    int pos;
    cin >> pos;
    if (pos >= 0 && pos < n) {
        nodes[n-1]->next = nodes[pos];
    }
    Node* head = nodes[0];
    unordered_set<Node*> st;
    Node* cur = head;
    bool loop = false;
    while (cur) {
        if (st.count(cur)) {
            loop = true;
            break;
        }
        st.insert(cur);
        cur = cur->next;
    }
    if (loop) cout << "true";
    else cout << "false";
    return 0;
}
