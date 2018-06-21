#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* my_itoa(int nmb)
{
  int i, j, k;
  char *y;

  i = 10;
  j = 0;
  k = 0;
  while (nmb / i != 0)
  {
    i *= 10;
    j++; //nmb symb amount
  }
  y = malloc (sizeof (char) * j + 1);
  i = 0;
  if (nmb < 0)
  {
    nmb *= -1;
    y[0] = '-';
    k++;
    j++;
  }
  while (j >= k)
  {
    y[j] = (nmb % 10) + '0';
    nmb /= 10;
    j--;
  }
  printf("%s\n", y);
  return y;
}
