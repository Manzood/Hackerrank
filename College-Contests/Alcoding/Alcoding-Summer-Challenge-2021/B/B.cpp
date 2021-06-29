#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    set <char> chars;
    for (int i = 0; i < n; i++) {
        chars.insert(s[i]);
    }
    bool ans = true;
    for (int i = 0; i < 26; i++) {
        if (chars.count('a' + i) == 0 && chars.count('A' + i) == 0) {
            ans = false;
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}
