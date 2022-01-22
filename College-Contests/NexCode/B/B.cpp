#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    string t = s;
    reverse (t.begin(), t.end());
    int q;
    scanf("%lld", &q);
    vector <int> a(q);
    for (int i = 0; i < q; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
        int val = a[i] / n;
        int rem = a[i] % n;
        bool reverse = false;
        if (val % 2 == 1) {
            reverse = true;
        }
        if (reverse == true) {
            cout << t[rem] << "\n";
        } else {
            cout << s[rem] << "\n";
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
