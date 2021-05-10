#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <bool> visited;
bool is_tree = true;
set <int> l;
set <int> r;

void dfs (int u, vector <vector <int>>& adj, int p, bool val) {
    if (visited[u]) return;
    // int retval = 2;
    visited[u] = true;
    if (val) l.insert(u);
    else r.insert(u);
    for (auto x: adj[u]) {
        if (visited[x] && x != p) {
            if ((val && l.count(x)) || (!val && r.count(x))) {
                is_tree = false;
            }
        }
        dfs(x, adj, u, !val);
    }
    // return retval;
}

int32_t main() {
    int n, f;
    scanf("%lld%lld", &n, &f);
    vector <vector <int>> adj(n);
    for (int i = 0; i < f; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.resize(n, false);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs (i, adj, -1, 1);
            ans *= 2;
        }
    }
    if (!is_tree) ans = 0;
    printf("%lld\n", ans);
}
