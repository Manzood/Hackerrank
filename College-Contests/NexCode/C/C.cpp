#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

long long power (long long a, long long b, int mod) {
	int result = 1;
	while (b) {
		if (b % 2 == 1) result *= a;
        result %= mod;
		a *= a;
        a %= mod;
		b /= 2;
	}
	return result;
}

void solve() {
    int b, e, p;
    scanf("%lld%lld%lld", &b, &e, &p);
    int mod = 1;
    for (int i = 0; i < p; i++) {
        mod *= 10;
    }
    int res = power (b, e, mod);
    string ans = to_string(res);
    if ((int) ans.size() < p) {
        reverse(ans.begin(), ans.end());
        int diff = p - (int) ans.size();
        for (int i = 0; i < diff; i++) {
            ans.push_back ('0');
        }
        reverse(ans.begin(), ans.end());
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
