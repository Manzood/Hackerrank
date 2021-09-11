#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, m;
    scanf("%lld%lld", &n, &m);
    string s;
    cin >> s;
    bool onefound = false;
    int pref = 0;
    int suff = 0;
    int longest = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            onefound = true;
            longest = max (suff, longest);
            suff = 0;
        } else {
            if (!onefound) {
                pref++;
            } else {
                suff++;
            }
        }
    }
    int ans = 0;
    if (onefound) {
        ans = pref + suff;
        ans = max (longest, ans);
    } else {
        ans = pref * m;
    }
    printf("%lld\n", ans);
}
