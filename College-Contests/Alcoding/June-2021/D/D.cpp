#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }
    sort (a.begin(), a.end());
    for (auto x: a) {
        printf("%lld %lld\n", x.first, x.second);
    }
    // vector <int> sum(n);
    // int s = 0;
    // for (int i = n - 1; i >= 0; i--) {
        // s += a[i].first;
        // sum[i] += s;
    // }
    int s = 0;
    int sb = 0;
    for (int i = 0; i < n; i++) {
        s += a[i].second;
        sb += a[i].first;
    }
    int cnt = 0;
    debug (s);
    debug (sb);
    for (int i = n - 1; i >= 0 && s <= sb; i--) {
        s += a[i].first;
        sb -= a[i].first;
        debug (s);
        debug (sb);
        cnt++;
    }
    printf("%lld\n", cnt);
}
