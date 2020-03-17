#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	float x,y;
	vector <float> x(n),y(n);
	vector <vector <int> > grid(n);
	for (int i=0;i<n;i++) {
		scanf ("%f%f",&x,&y);
		grid[i].push_back(x);
		grid[]
	}
	//printf("%f %f %f %f\n",maxX, maxY, minX, minY);
	float ans;
	ans=((maxX+1)-(minX-1))*2 + ((maxY+1)-(minY-1))*2;
	printf("%f",ans);
}