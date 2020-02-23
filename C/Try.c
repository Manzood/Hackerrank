#include <stdio.h>
#include <string.h>

int main()
{
	int arr[1000];
	int n;
	int i, j;

	scanf("%d", &n);

	memset (arr, 0, 1000*sizeof(arr[0]));

	for (i = 0; i < (n-1); i++)
	{
		scanf("%d", &j);
		arr[j-1]++;
		//printf ("%d %d", j, arr[j-1]);
	}

	for (i=0; i<n; i++)
		if (arr[i]==0)
		{
			printf("%d", (i+1));
			break;
		}

	return 0;
}