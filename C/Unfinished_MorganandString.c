#include <stdio.h>
//Very basic code set up
//Make sure to try the approach using temp to store any common characters in the compared strings
//Could be really fast, hypothetically

int main()
{
    int t;
    scanf ("%d\n", &t);

    while (t--)
    {
        char a[100000], b[100000];
        int c, lena, lenb;
        int i, j, k;
        lena = 0;
        lenb = 0;

        int temp;
    
        i = 0;
        j = 0;

        while ((c = getchar()) != '\n' && c != EOF)
        {
            a[lena] = c;
            lena++;
        }

        while ((c = getchar()) != '\n' && c != EOF)
        {
            b[lenb] = c;
            //printf ("b: %c\n", c);
            lenb++;
        }

        while (i < lena && j < lenb)
        {
            if (a[i] < b[j])
            {
                printf("%c", a[i]);
                i++;
            }

            else if (a[i] > b[j])
            {
                printf("%c", b[j]);
                j++;
            }

            else
            {
                printf("%c", a[i]);
                temp = a[i];
                i++;
                j++;
            }
        }
    }

    return 0;
}