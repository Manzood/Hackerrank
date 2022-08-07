#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = (int)1e18 + 7;

int get_ans(int l, int r, vector<vector<int>>& dp, string& s) {
    if (l > r) return dp[l][r] = 0;
    if (l == r) return dp[l][r] = 1;
    if (dp[l][r] != inf) return dp[l][r];
    dp[l][r] = get_ans(l + 1, r, dp, s) + 1;
    for (int i = l + 1; i <= r; i++) {
        if (s[l] == s[i])
            dp[l][r] = min(dp[l][r], get_ans(l + 1, i - 1, dp, s) + dp[i][r]);
    }
    return dp[l][r];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>(n, inf));
    // now to solve the iterative version completely
    // for (int i = n - 1; i >= 0; i--) {
    //     for (int j = i; j < n; j++) {
    //         if (i == j) {
    //             dp[i][j] = 1;
    //         } else if (i < n - 1) {
    //             dp[i][j] = dp[i + 1][j] + 1;
    //             for (int k = i + 2; k <= j; k++) {
    //                 if (s[k] == s[i]) {
    //                     dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] +
    //                     dp[k][j]);
    //                 }
    //             }
    //         }
    //     }
    // }
    int ans = get_ans(0, n - 1, dp, s);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
