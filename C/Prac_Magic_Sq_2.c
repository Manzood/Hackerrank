#include <stdio.h>

int Myownmagicsq(int s[3][3])
{
	int cost = 0;
	int i, j;
	int rsum[3], csum[3];
	int test = 0;
	int incompetence = 0;

	for (i=0; i<3; i++)
	{
		rsum[i] = 0;

		for (j=0; j<3; j++)
		{
			rsum[i] += s[i][j];
		}

		//printf("Sum of R%d = %d\n", i, rsum[i]);
	}

	for (i=0; i<3; i++)
	{
		csum[i] = 0;

		for (j=0; j<3; j++)
		{
			csum[i] += s[j][i];
		}

		//printf("Sum of C%d = %d\n", i, csum[i]);
	}

	while (test != 0)
	for (i=0; i<3; i++)	
	{
		if (i < 2)
			test = rsum[i+1] - rsum[i];

		else
		{
			test = rsum[2] - rsum[0];
			incompetence = 1;
		}

		if (test != 0 && incompetence != 1)
		{	
			for (j=0; j<2; j++)
			{
				if (csum[j] != csum[j+1])
				{	
					if (test > 0)
					{	
						if (csum[j] < csum[j+1])
						{
							s[i][j] += test;
							cost += test;
						}

						else 
						{
							s[i][j+1] += test;
							cost += test;
						}
					}

					else
					{
						if (csum[j] < csum[j+1])
						{
							s[i+1][j] -= test;
							cost -= test;
						}

						else
						{
							s[i+1][j+1] -= test;
							cost -= test;
						}
					}	
				}
			}

			if (csum[2] != csum[0])
			{
				if (csum[2] < csum[0])
				{
					if (test > 0)
					{	
						s[i][2] += test;
						cost += test;
					}

					else
					{
						s[i+1][2] -= test;
						cost -= test;
					}
				}

				else
				{
					if (test > 0)
					{
						s[i][0] += test;
						cost += test;
					}

					else
					{
						s[i+1][0] -= test;
						cost -= test;
					}
				}
			}
		}

		else if (test != 0)
		{
			for (j=0; j<2; j++)
			{
				if (csum[j] != csum[j+1])
				{	
					if (test > 0)
					{	
						if (csum[j] < csum[j+1])
						{
							s[0][j] += test;
							cost += test;
						}

						else 
						{
							s[0][j+1] += test;
							cost += test;
						}
					}

					else
					{
						if (csum[j] < csum[j+1])
						{
							s[2][j] -= test;
							cost -= test;
						}

						else
						{
							s[2][j+1] -= test;
							cost -= test;
						}
					}	
				}
			}

			if (csum[2] != csum[0])
			{
				if (csum[2] < csum[0])
				{
					if (test > 0)
					{	
						s[0][2] += test;
						cost += test;
					}

					else
					{
						s[2][2] -= test;
						cost -= test;
					}
				}

				else
				{
					if (test > 0)
					{
						s[0][0] += test;
						cost += test;
					}

					else
					{
						s[2][0] -= test;
						cost -= test;
					}
				}
			}
		}

		//i++;
	}

	return cost;
}

int main()
{
	int s[3][3];
	int i, j, cost;

	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}

	cost = Myownmagicsq(s);

	printf ("%d\n", cost);
}                                                                                                                      