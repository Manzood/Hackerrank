#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int mod = 1e9+7;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n + 1, 0);
        vector <int> b(n + 1, 0);
        vector <int> c(n + 1, 0);
        vector <int> d(n + 1, 0);
        d[0] = 1;
        for (int i = 1; i <= n; i++) {
            a[i] += b[i-1] + c[i-1] + d[i-1];
            b[i] += a[i-1] + c[i-1] + d[i-1];
            c[i] += b[i-1] + a[i-1] + d[i-1];
            d[i] += b[i-1] + c[i-1] + a[i-1];
            a[i] %= mod;
            b[i] %= mod;
            c[i] %= mod;
            d[i] %= mod;
        }
        printf("%lld\n", d[n]);
    }
}
