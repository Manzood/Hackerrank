#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int d;
    scanf("%lld", &d);
    vector <pair<int, int>> a(2 * d + 1);
    scanf("%lld%lld", &a[0].second, &a[0].first);
    vector <int> dist (2 * d + 1, 0);
    for (int i = 0; i < d; i++) {
        int x1, v1, x2, v2;
        scanf("%lld%lld%lld%lld", &x1, &v1, &x2, &v2);
        a[2*i + 1].second = x1;
        a[2*i + 1].first = v1;
        a[2*i + 2].second = x2;
        a[2*i + 2].first = v2;
        // debug(i);
        int minid = -1;
        int m = 1e18 + 7;
        for (int j = 2 * i; j >= 0; j--) {
            dist[j] += abs(a[j].first - a[2*i+1].first);
            dist[j] += abs(a[j].first - a[2*i+2].first);
        }
        for (int j = 0; j <= 2 * i + 2; j++) {
            dist[2*i+1] += abs(a[j].first - a[2*i+1].first);
            dist[2*i+2] += abs(a[j].first - a[2*i+2].first);
        }
        for (int j = 0; j <= 2 * i + 2; j++) {
            if (dist[j] < m) {
                // debug(dist[j]);
                // debug(j);
                m = dist[j];
                minid = a[j].second;
            }
        }
        printf("%lld\n", minid);
    }
}
