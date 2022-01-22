#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int mx = *max_element(a.begin(), a.end());
    sort(a.begin(), a.end());
    int mi = a[0];
    for (int i = 1; i < n; i++) {
        a[i] %= mi;
        if (a[i] > 0) {
            mi = min (a[i], mi);
        }
    }
    printf("%lld %lld\n", mi, mx);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
