#include <stdio.h>

int main()
{
    int t;
    scanf ("%d\n", &t);

    while (t--)
    {
        char a[100000], b[100000];
        int c, lena, lenb;
        lena = 0;
        lenb = 0;

        while ((c = getchar()) != '\n' && c != EOF)
        {
            a[lena] = c;
            //printf("a: %c\n", c);
            lena++;
        }

        while ((c = getchar()) != '\n' && c != EOF)
        {
            b[lenb] = c;
            //printf ("b: %c\n", c);
            lenb++;
        }

        int i, j, k;
        i = 0;
        j = 0;
        //int count = 0;

        //printf ("%s\n", a);
        //printf ("%s\n", b);
        
        while (i < lena && j < lenb)
        {
            //printf ("a[i] = %c", a[i]);
            k = 0;
            //count++;
            //if (count>100)
            //{
                //return 0;
            //}

            //printf("%c", a[i+k]);
            //printf("%c", b[j+k]);

            while (a[i+k]==b[j+k] && (i+k) < lena && (j+k) < lenb)
            {
                k++;
                //printf ("looped\n");
            }

            if ((a[i+k] > b[j+k]) && j < lenb)
            {
                printf("%c", b[j]);
                j++;
            }

            else if (i < lena)
            {
                printf ("%c", a[i]);
                i++;
            }
        }

        while (i < lena)
        {
            printf ("%c", a[i]);
            i++;
        }

        while (j < lenb)
        {
            printf ("%c", b[j]);
            j++;
        }

        printf ("\n");
    }

    return 0;
}
