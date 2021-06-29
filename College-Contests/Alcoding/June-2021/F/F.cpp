#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <int> a(n), b(m);
    set <int> bset;
    // vector <int> first_occurance (m, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        bset.insert (b[i]);
    }

    vector <int> odd;
    map <int, int> occurances;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        occurances[a[i]]++;
        if (bset.count(a[i])) {

        }
        if (odd.size() == 0) {
            ans = i + 1;
        } else {

        }
    }
}
