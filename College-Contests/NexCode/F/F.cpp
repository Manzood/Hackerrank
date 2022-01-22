#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n, H, k;
    scanf("%lld%lld%lld", &n, &H, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    int shield = H;
    int ans = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    int cur = 0;
    int sz = 0;
    int cnt = 1;
    for (int i = n - 1; i >= 0; i--) {
        shield += k;
        if (i == n - 1 && n >= 2) {
            cur = a[n-1] + a[n-2];
            sz = 2;
        } else if (i - 1 >= 0) {
            cur += a[i-1];
            sz++;
        }
        int val = sum + cur * (sz - 1);
        // debug (val);
        // debug (shield);
        if (val >= shield) {
            ans = cnt;
            break;
        }
        cnt++;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
