#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool checkfine(long long num) {
	bool flag=true;
	while (flag && num) {
		if (num%5==0) {
			num/=5;
		}
		else {
			num-=1;
			if (num%5!=0) {
				flag=false;
			}
		}
	}
	return flag;
}

long long getfine(long long num) {
	bool flag=true;
	long long ans=0;
	while (num) {
		debug(num);
		debug(ans)
		if (num%5==0) {
			num/=5;
			if (ans==0)
				ans++;
			ans*=5;
		}
		else {
			num-=1;
			if (num==0)
				break;
			if (num%5!=0) {
				while (!checkfine(num))
					num++;
				printf("here\n");
				debug(num);
			}
			else {
				ans++;
			}
		}
	}
	return (ans);
}

int main() {
	int t;
    cin>>t;
    while (t--) {
        long long num;
        scanf("%lld",&num);    
        if (!checkfine(num)) {
        	num+=(5-(num%5));
        }
        if (num%10==0)
        	num+=5;
        bool odd=true;
        while (checkfine(num)==false) {
        	if (odd) {
            num+=1;
            	odd=false;
            }
            else {
            	num--;
            	num+=10;
            	odd=true;
            }
        }
        printf("%lld\n",num);        
    }
}