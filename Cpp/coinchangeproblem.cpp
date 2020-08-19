#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int MX = 1e9;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> coins(m);
    for (int i = 0; i < m ; i++) {
        scanf("%d", &coins[i]);
    }
    vector <int> dp(n+1, 0);
    // storing the number of ways
    for (auto x: coins) {
        dp[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int x: coins) {
            if (i - x >= 0) {
                dp[i] += dp[i-x];
            }
        }
        cout << i << " , ";
        debug(dp[i]);
    }
    printf("%d\n", dp[n]);
}