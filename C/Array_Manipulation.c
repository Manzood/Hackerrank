#include <stdio.h>

int main()
{
    int n, m;
    unsigned long long int a, b, k;
    int i;
    unsigned long long int max;

    max = 0;

    scanf("%d %d", &n, &m);

    long long int arr[n];    

    for (i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    while (m--)
    {
        scanf("%lld %lld %lld", &a, &b, &k);
        for (i=a-1; i<b; i++)
        {
            arr[i]+=k;
            if (arr[i]>max)
                max = arr[i];
        }
    }

    printf("%lld", max);

    return 0;
}