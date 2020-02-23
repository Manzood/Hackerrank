#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    
    int i, j, num;

    for (i = 1; i < (2*n); i++)
    {
        for (j = 1; j < (2*n); j++)
        {
            if(i<=n && j<=n)
            {
                if (i<j)
                {
                    num=i;
                }

                else 
                {
                    num=j;
                }   

                if((n-num+1)>0)
                {
                   printf("%d ", n-num+1);
                }
            }

            else if (i<=n || j<=n)
            {
                if (i>j)
                {
                    if (j<(2*n-i))
                    {
                        num = j;
                    }

                    else
                    {
                        num = 2*n-i;
                    }
                }

                else
                {
                    if (i<(2*n-j))
                    {
                        num = i;
                    }

                    else
                    {
                        num = (2*n)-j;
                    }
                }

                printf("%d ", n-num);
            }

            else
            {
                if ((2*n-i) > (2*n-j))
                {
                    num = (2*n) - i;
                }

                else
                {
                    num = (2*n) - j;
                }

                printf("%d ", n-num);
            }
        }

        printf("\n");
    }

    return 0;
}

