#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector <int> a(n);
		int temp;
		bool possible=true;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (i==0) temp=a[i];
			else {
				if ((a[i]-temp)%2!=0)
					possible=false;
			}
		}
		if (possible) 
			printf("YES\n");
		else 
			printf("NO\n");
	}
}