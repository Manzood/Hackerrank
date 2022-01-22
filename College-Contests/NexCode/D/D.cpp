#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int k, l;
    scanf("%lld%lld", &k, &l);
    int val = min (k, l);
    int ans = (val % 10) + (val / 10);
    // debug (ans);
    ans %= 10;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
