#include <stdio.h>

void getinput(int obs[][], int n, int k, int q[][])
{
	int i;
	scanf ("%d %d", &n, &k);
	scanf ("%d %d", q[0][0]);

	for (i = 0; i < k; i++)
		scanf ("%d %d", obs[0][i], obs[1][i]);
}

int main()
{
	int n, k, q[1][1], i;
	int obs [2][10000];
	int grid[10000][10000];

	getinput(obs, n, k, q);

	for (i = 0; i < k; i++)
	{
		grid[obs[0][i]],obs[1][i] = 1;

		for (j = 0; j < k; j++)
		{ 
			if (grid[i][j] != 1)
				grid[i][j] = 0;
		}
	}

	for (i=q[0])
}