#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int inf = (int)1e18 + 7;

void solve([[maybe_unused]] int test) {
    int n, b;
    scanf("%lld%lld", &n, &b);
    vector<vector<int>> dp(n, vector<int>(b + 1, inf));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    map<int, int> found;
    for (int i = n - 1; i >= 0; i--) {
        found[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= b; j++) {
            if (i > 0) dp[i][j] = dp[i - 1][j];
        }
        if (found.count(i + 1)) {
            int ind = found[i + 1];
            int val = ind - i;
            dp[i][1] = min(dp[i][1], val);
            for (int j = 1; j <= b; j++) {
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + val);
            }
        }
    }
    // debug(dp);
    if (dp[n - 1][b] == inf) {
        dp[n - 1][b] = -1;
    }
    printf("%lld\n", dp[n - 1][b]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
