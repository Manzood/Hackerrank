#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int mod = (int) 1e9 + 7;

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += c[i];
        sum %= mod;
    }
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += b[i] * sum;
        sum2 %= mod;
    }
    int sum3 = 0;
    for (int i = 0; i < n; i++) {
        sum3 += a[i] * sum2;
        sum3 %= mod;
    }
    printf("%lld\n", sum3);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
