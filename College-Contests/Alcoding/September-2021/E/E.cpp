#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int rand (int a, int b) {
    return a + (rand() % (b - a + 1));
}

int32_t main () {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    int t1 = 0, t2 = 0;
    priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> pq1, pq2;
    set <int> s1, s2;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pq1.push({a[i], i});
        s1.insert(i);
        t1 += a[i];
    }
    int ans = t1;
    while (t1 > t2) {
        pair <int, int> v1 = pq1.top();
        int val = v1.first;
        t1 -= val;
        t2 += val;
        pq1.pop();
        if (s1.size()) s1.erase(v1.second);
        pq2.push(v1);
        s2.insert(v1.second);
        ans = min (ans, max (t1, t2));
    }
    // debug (s2.size());
    // pair <int, int> v1 = pq2.top();
    // int val = v1.first;
    // t1 += val;
    // t2 -= val;
    // ans = min (ans, max (t1, t2));
    // v1 = pq1.top();
    // val = v1.first;
    // t1 -= val;
    // t2 += val;
    // ans = min (ans, max (t1, t2));
    for (int i = 0; i < 10000; i++) {
        int ind;
        int cnt = 0;
        if (t1 > t2) {
            do {
                ind = rand (0, n - 1);
                cnt++;
            } while (s1.count(ind) == 0 && cnt < 100);
            if (cnt == 100) {
                t1 += a[ind];
                t2 -= a[ind];
                if (s2.size()) s2.erase(ind);
                s1.insert(ind);
                ans = min (ans, max (t1, t2));
            } else {
                t1 -= a[ind];
                t2 += a[ind];
                if (s1.size()) s1.erase(ind);
                s2.insert(ind);
                ans = min (ans, max (t1, t2));
            }
        } else {
            do {
                ind = rand (0, n - 1);
                cnt++;
            } while (s2.count(ind) == 0 && cnt < 100);
            if (cnt == 100) {
                t1 -= a[ind];
                t2 += a[ind];
                if (s1.size()) s1.erase(ind);
                s2.insert(ind);
                ans = min (ans, max (t1, t2));
            } else {
                t1 += a[ind];
                t2 -= a[ind];
                if (s2.size()) s2.erase(ind);
                s1.insert(ind);
                ans = min (ans, max (t1, t2));
            }
        }
    }
    printf("%lld\n", ans);
}
