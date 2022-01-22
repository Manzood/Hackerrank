#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int MAXN = 5;

int n;
vector <int> t(4 * MAXN);
void build(vector <int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        // t[v] = 0;
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update_set(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_set(v*2, tl, tm, pos, new_val);
        else
            update_set(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] = -t[v];
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

void solve() {
    int q;
    scanf("%lld%lld", &n, &q);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    build(a, 1, 0, n - 1);
    debug (t);
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        if (query == "neg") {
            int l, r;
            scanf("%lld%lld", &l, &r);
            update (1, 0, n - 1, l - 1, r - 1);
        } else if (query == "set") {
            int x, y;
            scanf("%lld%lld", &x, &y);
            update_set (1, 0, n - 1, x - 1, y);
        } else {
            int l, r;
            scanf("%lld%lld", &l, &r);
            int ans = get (1, l - 1, r - 1, 0);
            printf("%lld\n", ans);
        }
    }
}

int32_t main() {
    // int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= 1; tt++) {
        solve();
    }
}
