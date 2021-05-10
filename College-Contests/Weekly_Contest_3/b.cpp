#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	scanf("%d",&n);
	long long k;
	scanf("%lld",&k);
	vector <int> a(n);
	vector <long long> pref(n+1);
	pref[0]=0;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		pref[i+1]=a[i]+pref[i];
		//debug(pref[i]);
	}
	if (k>pref[n]) { 
		printf("0\n");
		return 0;
	}
	long long ans=0;
	for (int i=0;i<n+1;i++) {
		for (int j=i+1;j<n+1;j++) {
			if (pref[j]-pref[i]==k) {
				ans++;
			}
			if (pref[j]-pref[i]>k) {
				break;
			}
		}
	}
	printf("%lld\n",ans);
}