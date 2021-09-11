#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

class dsu {
  public:
    vector <int> p;
    vector <int> size;
    int n;
    dsu (int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
    }
    int parent(int x) {
        // path compression takes place here
        if (x == p[x]) return x;
        else return p[x] = parent(p[x]);
    }
    inline bool unite (int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x != y) {
            if (size[x] > size[y])
                swap(x, y);
            p[x] = y;
            int temp = size[x];
            size[x] += size[y];
            size[y] += temp;
            return true;
        }
        return false;
    }
};

int32_t main () {
    int n, q;
    scanf("%lld%lld", &n, &q);
    dsu d(n + 1);
    for (int i = 0; i < q; i++) {
        int query;
        scanf("%lld", &query);
        if (query == 1) {
            int a, b;
            scanf("%lld%lld", &a, &b);
            d.unite(a, b);
        } else {
            int x;
            scanf("%lld", &x);
            x = d.parent(x);
            int ans = d.size[x];
            printf("%lld\n", ans);
        }
    }
    // for (int i = 1; i <= n; i++) {
        // printf("%lld\n", i);
        // printf("%lld %lld\n\n", d.parent(i), d.size[d.parent(i)]);
    // }
}
