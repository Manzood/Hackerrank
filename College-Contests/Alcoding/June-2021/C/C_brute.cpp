#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i].first == a[j].first) cnt++;
            else if (a[i].first == a[j].second) cnt++;
            else if (a[i].second == a[j].first) cnt++;
            else if (a[i].second == a[j].second) cnt++;
        }
    }
    printf("%lld\n", cnt);
}
