#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<string>

using namespace std;


#define debug(x) cout<<x<<endl;

const int MOD = 1e8+7;

int main() {
    char s[100000];
    int i=0;
    int c;
    int current;
    int previous;
    int ans=1;
    int toggle;
    int prevcurrent,x;
    while((c=getchar())!='\n'&&c!=EOF) {
        s[i]=c;
        current=c-'a';
        if (current<15) {
            if (current%3==0);
            else if (current%3==1) {
                ans=ans*2;
            }
            else
                ans=ans*4;
            toggle=0;
        }
        else {
            current-=15;
            if (current<4) {
                if (current%4==0);
                else if (current%4==1) {
                    ans=ans*2;
                }
                else if (current%4==2) {
                    ans=ans*4;
                }
                else
                    ans*=8;
                toggle=1;
            }
            else if (current<7) {
                current-=4;
                if (current%3==0);
                else if (current%3==1) {
                    ans=ans*2;
                }
                else
                    ans=ans*4;
                toggle=2;
            }
            else {
                current-=7;
                if (current%4==0);
                else if (current%4==1) {
                    ans=ans*2;
                }
                else if (current%4==2) {
                    ans=ans*4;
                }
                else
                    ans*=8;
                current+=7;
                toggle=3;
            }
        }
        x=current/3;
        if (i>0) {
            if (previous==toggle && x==prevcurrent)
                ans*=2;
        }
        previous=toggle;
        prevcurrent=x;
        ans=ans%MOD;
        i++;
    }
    cout<<ans;
}