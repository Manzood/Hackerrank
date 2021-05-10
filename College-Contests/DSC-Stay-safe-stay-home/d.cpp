#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
// repair roads

int bots;
vector <bool> visited;
void search (vector <pair<int, int> > roads, int num) {
	if (visited[num]) return;
	visited[num] = true;
	

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		vector <pair<int, int> > roads;
		for (int i=0; i<n-1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			roads.push_back(make_pair(u,v));
		}
		for (int i=0; i<n-1; i++) {
			visited[i] = false;
		}
		int count = 0;
		bots = 1;
		while (count < n-1) {
			
