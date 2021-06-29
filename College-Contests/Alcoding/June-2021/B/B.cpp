#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    int ans = 0;
    int bor = 0;
    for (int i = 0; i < m; i++) {
        bor |= b[i];
    }
    for (int i = 0; i < n; i++) {
        ans |= a[i] & bor;
    }
    printf("%lld\n", ans);
}
