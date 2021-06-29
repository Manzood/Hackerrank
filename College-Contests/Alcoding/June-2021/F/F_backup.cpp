#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n), b(m);
    vector <int> first_occurance (m, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j] && first_occurance[j] == -1) {
                first_occurance[j] = i;
            }
        }
    }
    // for (int i = 0; i < m; i++) {
        // debug (first_occurance[i]);
    // }
    map <int, int> occurances;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int curlen = i + 1;
        occurances[a[i]]++;
        for (int j = 0; j < m; j++) {
            if (occurances[b[j]] % 2 == 1) {
                curlen = min (curlen, i - first_occurance[j]);
            }
        }
        ans = max (curlen, ans);
        // debug (i);
        // debug (curlen);
        // debug (ans);
    }
    printf("%lld\n", ans);
}
