#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int k;
    int n, q;
    scanf ("%d %d", &n, &q);
    
    vector <vector <int> > a(n);
    int i, j;

    for (i = 0; i < n; i++)
    {
        scanf ("%d", &k);
        for (j = 0; j < k; j++)
        {
            scanf ("%d", &a[i][j]);
        }
    }

    while (q--)
    {
        scanf ("%d %d", &i, &j);
        printf ("%d\n", a[i][j]);
    }

    return 0;
}

