#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long
using namespace std;

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int mx = *max_element(a.begin(), a.end());
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i += 2) {
        cur = max (cur, mx - a[i]);
    }
    ans += cur;
    cur = 0;
    for (int i = 1; i < n; i += 2) {
        cur = max (cur, mx - a[i]);
    }
    ans += cur;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
