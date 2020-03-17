#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>

using namespace std;

#define debug(x) cout<<x<<endl;
const int MAX = 1e9;

int check(char* s, int start, int finish) {
	char a=s[start];
	for (int i=start+1;i<=finish;i++) {
		if (s[i]!=a) {
			return 0;
		}
	}
	return 1;
}

int checked=0;

int checkstring (char*s, int start,int finish) {
	int len=finish-start+1;
	int left,right;
	//debug(len);
	int ans=0;
	//debug(check(s,start,finish));
	if (check(s,start,finish) && len>=2) {
		return 0;
	}
	else {
		if (len%2==0 && len>=2) {
			int right=checkstring(s,start+len/2,finish);
			int left=checkstring(s,start,finish-len/2);
			if (right>=0 && left>=0) {
				if (left<right) {
					return left+1;
				}
				else
					return right+1;
			} 
			else if (right>=0) {
				return right+1;
			}
			else if (left>=0)
				return left+1;
			else
				return -1;
		}
		else
			return -1;
	}
}

int main() {
	char *s;
	s=(char*)malloc(sizeof(char));
	scanf("%s",s);
	int len=strlen(s);
	int start=0;
	int finish=len-1;
	int ans=0;
	ans=checkstring(s,start,finish);
	cout<<ans;
}