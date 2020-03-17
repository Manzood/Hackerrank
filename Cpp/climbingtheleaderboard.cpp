#include <bits/stdc++.h>

using namespace std;

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int n=scores.size();
    int m=alice.size();
    vector <int> rank(m);
    int pos=0;
    rank[0]=1;
    for (int i=0;i<n;i++) {
        if (alice[0]<scores[i]) {
            rank[0]++;
            pos++;
        }
        else
            break;
    }
    //printf("%d\n",pos);
    for (int i=1;i<m;i++) {
        rank[i]=rank[i-1];
        while (scores[pos]<alice[i] && pos>=0) {
            if (scores[pos]>scores[pos+1] && rank[i]>1)
                rank[i]--;
            pos--;
        }
    }
    return rank;
}

int main() {
    int n;
    cin>>n;
    vector <int> scores(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&scores[i]);
    }
    int m;
    cin>>m;
    vector <int> alice(m);
    for (int i=0;i<m;i++)
        scanf("%d",&alice[i]);
    vector <int> ans(m);
    ans = climbingLeaderboard(scores, alice);
    for (int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}