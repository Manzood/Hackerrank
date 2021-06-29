#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    int x, y;
    map <int, int> nums;
    map <pair <int, int>, int> rep;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x, &y);
        if (x == y) {
            ans += nums[x];
            nums[x]++;
        } else {
            ans += nums[x];
            ans += nums[y];
            nums[x]++;
            nums[y]++;
            ans -= rep[{x, y}];
            ans -= rep[{y, x}];
            // ans -= rep.count ({y, x});
            rep[{x, y}]++;
        }
    }
    printf("%lld\n", ans);
}
