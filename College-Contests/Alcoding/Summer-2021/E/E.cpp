#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
// #define int long long

int32_t main() {
    int d;
    scanf("%d", &d);
    vector <pair<int, int>> a(2 * d + 1);
    scanf("%d%d", &a[0].second, &a[0].first);
    priority_queue <pair <int, int>> left;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> right;
    left.push ({a[0].first, a[0].second});
    for (int i = 0; i < d; i++) {
        int x1, v1, x2, v2;
        scanf("%d%d%d%d", &x1, &v1, &x2, &v2);
        // a[2*i + 1].second = x1;
        // a[2*i + 1].first = v1;
        // a[2*i + 2].second = x2;
        // a[2*i + 2].first = v2;
        if (left.top().first < v1) {
            // add to right
            right.push ({v1, x1});
        } else {
            left.push ({v1, x1});
        }
        if (left.top().first < v2) {
            // add to right
            right.push ({v2, x2});
        } else {
            left.push ({v2, x2});
        }
        if (abs ((int) right.size() - (int) left.size()) >= 2) {
            if (left.size() < right.size()) {
                pair <int, int> temp = right.top();
                left.push (temp);
                right.pop();
            } else {
                pair <int, int> temp = left.top();
                right.push (temp);
                left.pop();
            }
        }
        if (left.size() > right.size()) {
            printf("%d\n", left.top().second);
        } else {
            printf("%d\n", right.top().second);
        }
    }
}
