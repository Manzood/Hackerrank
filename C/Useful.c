#include <stdio.h>

int quicksort(int arr[], int len)
{
	int n = (len+1)/2;

	int left[n];
	int right[n];

	int i = 0;
	int lc = 0;
	int rc = 0;
	
	int p = arr[i];

	if (len > 1)
	for (i = 1; i < n; i++)
	{
		if (arr[i] < p)
		{
			left[lc] = arr[i];
			lc++;
		}

		else 
		{
			right[rc] = arr[i];
			rc++;
		}

		quicksort(left, lc);
		quicksort(right, rc);
	}

	return 0;
}

int main()
{
	int arr[1000];
	int n, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf ("%d", &arr[i]);
	}

	quicksort(arr, n);

	for (i = 0; i < n; i++)
	{
		printf ("%d ", arr[i]);
	}

	return 0;
}

/*
pen and paper

first i'll add split them into to halves
then, each split can be considered
for example, 
8 integers provided
first four considered
since len > 2
split again
consider first two
order em up
then take second pair of two, and so forth
after which, compare pairs
consider the first four
if the smalles of the first couple is larger than the largest of the second one, switch em up (or vice versa)
following which, do it for the pther four
then do it between the fours, place this four where the other ones should have been placed
*/