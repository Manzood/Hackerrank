#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool checkpalindrome (int i, int len, vector <int> a) {
	if (len==3) {
		if (a[i]==a[i+2])
			return true;
	}
	else {
		if (a[i]==a[i+3] && a[i+1]==a[i+2]) 
			return true;
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		bool ans=false;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for (int i=0;i<n-2;i++) {
			if (i==n-3) { 
				if (checkpalindrome(i,3,a))
					ans=true;
			}
			else {
				if (checkpalindrome(i,4,a) || checkpalindrome(i,3,a))
					ans=true;
			}
		}
		if (ans) 
			printf("YES\n");
		else
			printf("NO\n");
	}
}
