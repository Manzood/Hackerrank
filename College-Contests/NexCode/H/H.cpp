#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int INF = (int) 1e18 + 7;

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;

// void dijkstra(vector <vector <pair<int, int>>>& adj, int s, priority_queue<pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> min_pq) {
//     int n = adj.size();
//     d.assign(n, INF);
//     // p.assign(n, -1);
//     vector<bool> u(n, false);
//
//     d[s] = 0;
//     for (int i = 0; i < n; i++) {
//         int v = -1;
//         for (int j = 0; j < n; j++) {
//             if (!u[j] && (v == -1 || d[j] < d[v]))
//                 v = j;
//         }
//
//         if (d[v] == INF)
//             break;
//
//         u[v] = true;
//         for (auto edge : adj[v]) {
//             int to = edge.first;
//             int len = edge.second;
//
//             if (d[v] + len < d[to]) {
//                 d[to] = d[v] + len;
//                 // p[to] = v;
//             }
//         }
//     }
// }

void solve() {
    int n, m, x, y;
    scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
    vector <vector <pair <int, int>>> adj;
    vector <vector <vector <int>>> times;
    vector <int> d(n, INF);
    priority_queue<pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> min_pq;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        scanf("%lld%lld%lld", &u, &v, &t);
        u--; v--;
        adj[u].push_back ({v, t});
        adj[v].push_back ({u, t});
        for (int j = 0; j < 5; j++) {
            int k;
            scanf("%lld", &k);
            times[u][v].push_back(k);
            times[v][u].push_back(k); // maybe comment this out?
        }
    }
    min_pq.push ({0, x});
    for (int i = 0; i < n; i++) {
        if (i != x) {
            min_pq.push({INF, i});
        }
    }
    while (!min_pq.empty()) {
        int cur = min_pq.top().second;
        int val = min_pq.top().first;
        for (auto edge: adj[cur]) {
            int dest = edge.first;
            int dist = edge.second;
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
