#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        set <int> st;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            st.insert (a[i]);
        }
        (int)st.size() == n ? printf("Yes\n") : printf("No\n");
    }
}
