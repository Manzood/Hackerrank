#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, p;
        scanf("%lld %lld", &n, &p);
        long long count = 0;
        long long x = 1;
        long long ans;
        int l = 0;
        while (x <= n) {
            ans = 0;
            for (long long k=0; k<=n; k++) {
                long long fact = 1;
                for (long long i=n; i>max(k, n-k) && i>1; i--) 
                    fact*=i;
                for (long long i=1; i<=min(n-k, k); i++)
                    fact/=i;
                if ((fact % x) == 0 && (x*p<0 || (fact % (x*p)) != 0)) {
                    ans++;
                }
            }
            if (ans > 0) {
                while (count < l) {
                    printf("0 ");
                    count++;
                }
                printf("%lld ", ans);
                count++;
            }
            l++;
            x*=p;
        }
        printf("\n");
    }
}