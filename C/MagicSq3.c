#include <stdio.h>

int MagicSq(int s[3][3])
{
	int i, j;
	int rows[3];
	int cols[3];
	int cost = 0;

	/*for (i=0; i<3; i++)
	{
		rows[i] = 0;
		cols[i] = 0;

		for (j=0; j<3; j++)
		{
			rows[i] += s[i][j];
			cols[i] += s[j][i];
		}
	}*/

	int rmax, rmin, rmid;

	int cmax, cmin, cmid;

	int cmindex, cmaxdex, rmindex, rmaxdex, rmiddex, cmiddex;

	int test = 1;
	int diffr, diffc;

	int k;

	int x = 0;

	diffc = 1;

	while (test != 0)
	{
		/*for (i=0; i<2; i++)
		{
			diff = rows[i+1] - rows[i];

			if (diff != 0)
			{
				break;
			}
		}*/

		//for (i=0; i< 3; i++)
		//{	
			for (j=0; j<3; j++)
			{
				rows[j] = 0;
				cols[j] = 0;

				for (k=0; k<3; k++)
				{
					rows[j] += s[j][k];

					cols[j] += s[k][j];
				}

				//printf("row %d = %d\n", j, rows[j]);
				//printf("col %d = %d\n", j, cols[j]);
			}

			rmax = rows[0];
			rmin = rows[0];
			rmid = rows[0];

			cmax = cols[0];
			cmin = cols[0];
			cmid = cols[0];

			cmindex = 0;
			cmaxdex = 0;
			cmiddex = 0;
			rmindex = 0;
			rmaxdex = 0;
			rmiddex = 0;

			/*
			4 8 2
			4 5 7
			6 1 6
			*/

			int maxdiff, mindiff;

			for (i=0; i<3; i++)
			{
				if (rmax < rows[i])
				{
					rmiddex = rmaxdex;
					rmid = rmax;
					rmax = rows[i];
					rmaxdex = i;
				}

				if (rmin > rows[i])
				{
					rmiddex = rmindex;
					rmid = rmin;
					rmin = rows[i];
					rmindex = i;
				}
			}	

				//printf ("%d\n", rmaxdex);
			
				/*if (rmax >= rows[i] && rmin <= rows [i])                              //I don't even need this one smh
				{
					rmid = rows[i];
				}*/
				//printf("row %d = %d\n", i, rows[i]);
				//printf("col %d = %d\n", i, cols[i]);

				//printf("rmax = %d\n", rmax);
				//printf("rmid = %d\n", rmid);
				//printf("rmin = %d\n", rmin);

				//printf("row %d = %d\n", i, rows[i]);

				diffr = rmax - rmin;

				//maxdiff = rmax - rmid;

				printf("diffr = %d\n", diffr);

				if (diffr != 0 || diffc != 0)
				{
					for (j=0; j<3; j++)
					{
						if (cmax < cols[j])
						{
							cmiddex = cmaxdex;
							cmid = cmax;
							cmax = cols[j];
							cmaxdex = j;
						}

						else;

						if (cmin > cols[j])
						{
							cmiddex = cmaxdex;
							cmid = cmin;
							cmin = cols[j];
							cmindex = j;
						}

						else;
					}

					diffc = cmax - cmin;

					printf("diffc = %d\n", diffc);					

					printf("cmax = %d\n", cmax);
					printf("cmid = %d\n", cmid);
					printf("cmin = %d\n", cmin);

					maxdiff = rmax - rmid;
					mindiff = rmid - rmin;

					//printf ("Midnumber at %d, %d = %d\nMinnumber at %d, %d = %d\n", rmiddex, cmiddex, s[rmiddex][cmiddex], rmindex, cmindex, s[rmindex][cmindex]);

					printf("maxdiff = %d\n", maxdiff);
					printf("mindiff = %d\n", mindiff);

					//printf("%d\n", rmaxdex);
					//printf("%d\n", cmaxdex);
					//printf("%d\n", s[rmaxdex][cmaxdex]);

					/*for (i=0; i<3; i++)
					{
						for (j=0; j<3; j++)
						{
							printf ("%d ", s[i][j]);
						}

						printf("\n");
					}*/

					//if (diff > 0)
					//{	

						if (maxdiff > 0)
						{
							s[rmaxdex][cmaxdex] -= 1;
							cost += 1;

							rows[rmaxdex] -= 1;
							cols[cmaxdex] -= 1;
						}

						if (mindiff > 0)
						{
							s[rmindex][cmindex] += 1;
							cost += 1;

							rows[rmindex] += 1;
							cols[cmindex] += 1;
						}

						//cost += diff;

						//printf("cost = %d\n", cost);
					//}

					/*else
					{
						s[rmindex][cmindex] -= diff;
						rows[rmindex] -= diff;
						cols[cmindex] -= diff;
						cost -= diff;

						//printf("cost = %d\n", cost);
					}*/

				//test = 0;
				}

				if (diffr == 0 && diffc == 0)
					test = 0;

				if (x >3)
					test = 0;

				x++;
		//}

		//printf("diff = %d\n", diff);
	}

	//printf("cost = %d\n", cost);

	return cost;
}

int main()
{
	int s[3][3];
	int i, j;
	int cost = 0;

	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			scanf ("%d", &s[i][j]);
		}
	}

	cost = MagicSq(s);

	printf("%d\n", cost);

	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			printf ("%d ", s[i][j]);
		}

		printf("\n");
	}

	return 0;
}