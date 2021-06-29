#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int ans = 0;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        ans = 0;
        vector <int> l = {a[0]};
        for (int i = 1; i < n; i++) {
            if (a[i] >= l[(int)l.size() - 1]) {
                l.push_back (a[i]);
            } else {
                vector<int>::iterator idx = lower_bound(l.begin(), l.end(), a[i]);
                l[idx-l.begin()] = a[i];
            }
        }
        ans = n - (int) l.size();
        printf("%lld\n", ans);
    }
}
