#include <stdio.h>

int seq[8] = {2, 7, 6, 1, 8, 3, 4, 9};
int start = 0;

int newS[8];

void getinput(int s[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &s[i][j]);
			//printf("%d ", s[i][j]);
		}

		//printf ("\n");
	}
}

int change (int curr, int targ)
{
	int diff;

	diff = targ - curr;
	curr = targ;

	if (diff < 0)
		diff = (0 - diff);

	return diff;
}

int forward ()
{
	int cost = 0;
	int i, j;
	int k;
	int tally = 0;
	int max = 0;
	extern int start;
	start = 0;
	int mincost = 1000000000;
	int x;
	int fstart = 0;

	for (i = 0; i < 8; i++)
	{
		k = i;

		for (j = 0; j < 8; j++)
		{
			if (newS[k] == seq[j])
			{
				tally++;
			}

			k++;

			if (k > 7)
				k = 0;
		}

		if (tally >= max)
		{
			max = tally;
			start = k;
			
			for (x = 0; x < 8; x++)
			{
				if (newS[start] > seq[x])
					cost += (newS[start] - seq[x]);

				else if (newS[start] < seq[x])
					cost += (seq[x] - newS[start]);

				//printf("%d ", newS[start]);

				start++;

				if (start > 7)
					start = 0;
			}

			if (cost < mincost)
			{
				mincost = cost;
				fstart = start;
			}

			cost = 0;
		}
	}

	//Note: this could be used multiple times to calculate imrpovements in cost inside the loop

	/*for (i = 0; i < 8; i++)
	{
		printf ("%d ", newS[fstart]);
		fstart++;

		if (fstart > 7)
		{
			fstart = 0;
		}
	}*/

	//printf ("\n");

	/*for (i = 0; i < 8; i++)
	{
		printf("%d ", seq[i]);
	}*/

	//printf("\n");	

	return mincost;
}

int reverse ()
{
	int cost = 0;
	int i, j;
	int k;
	int tally = 0;
	int max = 0;
	extern int start;
	start = 0;
	int mincost = 1000000000;
	int x;
	int fstart = 0;

	for (i = 0; i < 8; i++)
	{
		k = i;

		for (j = 7; j > -1; j--)
		{
			if (newS[k] == seq[j])
			{
				tally++;
			}

			k++;

			if (k > 7)
				k = 0;
		}

		//k++;

		if (tally >= max)
		{
			max = tally;
			start = k + 1;

			for (x = 7; x > -1; x--)
			{
				if (newS[start] > seq[x])
					cost += (newS[start] - seq[x]);

				else if (newS[start] < seq[x])
					cost += (seq[x] - newS[start]);

				//printf("%d ", newS[k]);

				start++;

				if (start > 7)
					start = 0;
			}

			if (cost < mincost)
			{
				mincost = cost;
				fstart = start;
			}

			cost = 0;
		}
	}

	for (i = 0; i < 8; i++)
	{
		printf ("%d ", newS[fstart]);
		fstart++;

		if (fstart > 7)
		{
			fstart = 0;
		}
	}

	//Note: this could be used multiple times to calculate imrpovements in cost inside the loop

	printf ("\n");

	for (i = 7; i > -1; i--)
	{
		printf("%d ", seq[i]);
	}

	printf ("\n");

	return mincost;
}


int convert (int s[3][3], int newS[8])
{
	int addi = 1;
	int addj = 0;
	int x = 0;

	int i, j;

	i = 0;
	j = 0;

	while ((i != 0) || (j != 1))
	{
		newS[x] = s[i][j];
		//printf ("%d ", newS[x]);

		x++;
		i += addi;
		j += addj;

		if (i == 2)
		{
			addi = 0;
			addj = 1;
		}

		if (j == 2)
		{
			addj = 0;
			addi = -1;
		}

		if (i == 0 && j == 2)
		{
			addi = 0;
			addj = -1;
		}
	}

	newS[7] = s[0][1];

	return 0;
}

int main()
{
	int s[3][3];
	getinput(s);
	int costf = 0;
	int costr = 0;
	int cost = 0;

	if (s[1][1] != 5)
		cost += change (s[1][1], 5);

	convert (s, newS);

	costf = forward ();
	costr = reverse ();

	//printf("%d\n", costf);
	//printf("%d\n", costr);

	/*for (i = 0; i < 8; i++)
	{
		printf("%d ", newS[i]);
	}*/

	//printf("\n");

	/*for (i = 0; i < 8; i++)
		printf ("%d ", newS[i]);*/

	if (costf < costr)
		printf("%d", costf + cost);

	else
		printf("%d", costr + cost);

	return 0;
}