#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n), b(m);
    // set <int> bset;
    // vector <int> first_occurance (m, -1);
    map <int, int> occurances;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        // bset.insert (b[i]);
    }

    vector <int> mask(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) mask[i] = mask[i-1];
        occurances[a[i]]++;
        for (int j = 0; j < m; j++) {
            // int val = (1LL << j);
            // mask[i] ^= (occurances[b[j]] % 2) << j;
            // debug (occurances[1]);
            int val = occurances[b[j]] % 2;
            if (val == 1) {
                // debug (mask[i]);
                // debug (j);
                mask[i] |= (1 << j);
                // debug ((1 << j));
                // debug (mask[i]);
            } else {
                // set that one bit to zero
                mask[i] &= ~(1 << j);
            }
        }
    }
    map <int, int> maskvals;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // debug (mask[i])
        if (maskvals.count(mask[i])) {
            ans = max (ans, i - maskvals[mask[i]]);
        } else {
            maskvals[mask[i]] = i;
        }
        if (mask[i] == 0) ans = i + 1;
        // debug (ans);
    }
    printf("%lld\n", ans);
}
