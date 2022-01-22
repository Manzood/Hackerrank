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
    int n = min(k, l);
    int sum = 0;
    int carry = 0;
    for (int i = 0; i < n; i++) {
        sum = carry + i + 1;
        carry = sum / 10;
    }
    printf("%lld\n", sum % 10);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
