#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int x, q;
    scanf("%lld%lld", &x, &q);
    vector <pair <int, int>> a(q);
    for (int i = 0; i < q; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }
    sort (a.begin(), a.end());
    int r = 0;
    int ans = 0;
    for (int i = 0; i < q; i++) {
        if (r < a[i].first - 1) {
            ans = r + 1;
        }
        r = max (r, a[i].second);
    }
    if (ans == 0) ans = x;
    printf("%lld\n", ans);
}
