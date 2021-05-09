#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int ans = 0;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        // one from the left, one from the right
        ans = 0;
        // find longest ascending subsequence
        vector <int> dp (n, 1);
        int x = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] > a[j]) {
                    dp[i] = max (dp[j] + 1, dp[i]);
                    x = max (x, dp[i]);
                }
            }
        }
        ans = n - x;
        printf("%lld\n", ans);
    }
}
