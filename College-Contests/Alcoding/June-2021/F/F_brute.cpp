#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n), b(m);
    // vector <int> first_occurance (m, -1);
    set <int> bset;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        bset.insert(b[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        map <int, int> occurances;
        for (int j = i; j >= 0; j--) {
            if (bset.count(a[j])) occurances[a[j]]++;
            bool found = true;
            for (int k = 0; k < m; k++) {
                if (occurances[b[k]] % 2 == 1) {
                    found = false;
                }
            }
            if (found) ans = max (ans, i - j + 1);
        }
    }
    printf("%lld\n", ans);
}
