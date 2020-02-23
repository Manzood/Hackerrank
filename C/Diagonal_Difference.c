#include <stdio.h>

int main() {
  int n, i, j;

  scanf("%d", &n);

  int ar[n][n];

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &ar[j][i]);
    }
  }

  int sum1, sum2;

  sum1 = 0;
  sum2 = 0;

  for (i = 0; i < n; i++) {
    sum1 += ar[i][i];
  }

  printf("%d\n", sum1);

  for (i = n-1; i >= 0; i--) {
    sum2 += ar[i][n - i - 1];
  }

    printf("%d\n", sum2);

  int net;

  if (sum1 >= sum2)
    net = sum1 - sum2;

  else
    net = sum2 - sum1;

  printf("%d", net);

  return 0;
}