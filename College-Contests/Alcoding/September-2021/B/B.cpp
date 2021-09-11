#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == i + 1) cnt++;
    }
    printf("%lld\n", cnt);
}
