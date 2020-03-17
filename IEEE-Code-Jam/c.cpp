#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define debug(x) cout<<x<<endl;

int main() {
	int n;
	int ans=1;
	cin>>n;
	if (n==0)
		cout<<0;
	else if (n==1)
		cout<<1;
	else {
		for (int i=2;i<n*2;i+=2) {
			ans+=i*4+1;
		}
		cout<<ans;
	}
}