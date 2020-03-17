#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define debug(x) cout<<x<<endl;

int main() {
	unsigned long long n;
	cin>>n;
	int bye;
	int ans=0;	
	while(n>2) {
		bye=n%2;
		n=n/2;
		if (bye==1)
			ans++;
		n+=bye;
	}
	cout<<ans;
}