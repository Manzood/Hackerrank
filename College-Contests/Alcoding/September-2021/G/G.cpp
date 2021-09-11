#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int inf = 1e9 + 7;

struct segtree { // ZERO BASED INDEXING
    int size;
    vector <long long> sum;
    vector <long long> m;
    vector <long long> mx;
    void init (int n) { // just making our size a power of two
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2*size-1, 0);
        m.assign(2*size-1, inf);
        mx.assign(2*size-1, -inf);
    }
    void build (vector <int>& a) {
        int n = a.size();
        int numzeroes = size-n;
        int counter = 0;
        for (int i = 2*size-2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
                m[i] = inf;
                mx[i] = -inf;
            }
            else if (n > 0) {
                sum[i] = a[--n];
                m[i] = a[n];
                mx[i] = a[n];
            }
            else {
                sum[i] += sum[2*i+1] + sum[2*i+2];
                m[i] = min(m[2*i+1], m[2*i+2]);
                mx[i] = max(mx[2*i+1], mx[2*i+2]);
            }
        }
    }
    void set (int i, int v) { // setting index i to element v
        set (i, v, 0, 0, size);
    }
    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            m[x] = v;
            mx[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        m[x] = min(m[2 * x + 1], m[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
        return;
    }
    long long getsum (int left, int right) { // returns sum between indexes [left, right - 1], inclusive
        return getsum(left, right, 0, 0, size);
    }
    long long getsum (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int mid = (lx + rx) / 2;
        long long s1 = getsum (left, right, 2 * x + 1, lx, mid);
        long long s2 = getsum (left, right, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
    long long getmin (int left, int right) { // returns min between indexes [left, right - 1], inclusive
        return getmin(left, right, 0, 0, size);
    }
    long long getmin (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return inf;
        if (lx >= left && rx <= right) return m[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmin (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmin (left, right, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }
    long long getmax (int left, int right) { // returns max between indexes [left, right - 1], inclusive
        return getmax (left, right, 0, 0, size);
    }
    long long getmax (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return -inf;
        if (lx >= left && rx <= right) return mx[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmax (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmax (left, right, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }
};

int32_t main () {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    vector <int> tarray(n, 0);
    vector <pair<int,int>> order(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        order[i] = {a[i], i};
    }
    sort (order.begin(), order.end());
    segtree st;
    st.init(n + 1);
    st.build(tarray);
    vector <int> ans;

    for (int i = 0; i < n; i++) {
        int ind = order[i].second;
        int s = st.getsum (0, ind);
        ans.push_back (ind + 1 - s);
        st.set(ind, 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%lld\n", ans[i]);
    }

    printf("\n");
}
