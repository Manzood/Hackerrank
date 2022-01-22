#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long
const int inf = (int) 1e18 + 7;

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <vector <int>> t(k, vector <int> (n - 1));
    vector <vector <int>> w(k, vector <int> (n - 1));
    vector <vector <int>> ans(n, vector <int> (k, inf));
    // best answer reaching city i using transport j
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n - 1; i++) {
            scanf("%lld", &t[j][i]);
        }
    }
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n - 1; i++) {
            scanf("%lld", &w[j][i]);
        }
    }
    for (int j = 0; j < k; j++) {
        ans[0][j] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            ans[i][j] = inf;
            for (int x = 0; x < k; x++) {
                int wait = 0;
                if (x != j || i - 1 == 0) {
                    wait = w[j][i - 1];
                }
                ans[i][j] = min (ans[i][j], ans[i-1][x] + t[j][i-1] + wait);
            }
        }
    }
    int answer = inf;
    for (int j = 0; j < k; j++) {
        answer = min (answer, ans[n-1][j]);
    }
    // debug (ans);
    printf("%lld\n", answer);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
