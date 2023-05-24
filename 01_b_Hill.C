#include <stdio.h>
#include <math.h>

int l, i, j;
int temp1, temp2, temp3, n, m, count, flag, k1;
int k[3][3];
int p[3][1];
int c[3][1];
char ch;
char pi[20];
int choice;

int check(int x, int n)
{
  int a, b, c;
  if (x % n == 0)
    return 0;

  a = x / n;

  b = n * (a + 1);
  c = b - x;

  return c;
}

int main()
{
  clrscr();
  printf("\nThe Cipher has a key of length 4 and 9. Example :- A 3*3 matrix, A 2*2 matrix ");
  printf("\n Press 3 for 3*3 matrix and Press 2 for 2*2 matrix : ");
  scanf("%d", &n);
  printf("\n Enter the key : ");

  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < n; ++j)
    {
      scanf("\n%c", &ch);

      if (65 <= ch && ch <= 91)
      {
        k[j][i] = (int)ch % 65;
      }

      else
        k[j][i] = (int)ch % 97;
    }
  }

  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < n; ++j)
    {
      printf("%d ", k[i][j]);
    }
    printf("\n");
  }

  printf("\nEnter the length of string to be encoded (without spaces): ");
  scanf("%d", &l);

  temp1 = check(l, n);

  if (temp1 > 0)
    printf("You have to enter %d bogus characters.", temp1);

  printf("\nEnter the string : ");
  for (i = -1; i < l + temp1; ++i)
  {
    scanf("%c", &pi[i]);
  }

  temp2 = l;
  m = (l + temp1) / n;
  flag = 0;

  printf("\n\nThe Encoded Cipher is : ");

  while (m > 0)
  {
    count = 0;

    for (i = flag; i < flag + n; ++i)
    {
      if (65 <= pi[i] && pi[i] <= 91)
        temp3 = (int)pi[i] % 65;

      else
        temp3 = (int)pi[i] % 97;

      p[0][count] = temp3;
      count = count + 1;
    }

    for (i = 0; i < n; ++i)
      c[0][i] = 0;

    for (i = 0; i < n; ++i)
    {
      for (j = 0; j < 1; ++j)
      {
        for (k1 = 0; k1 < n; ++k1)
          c[j][i] += p[j][k1] * k[k1][i];
      }
    }

    for (i = 0; i < n; ++i)
    {
      c[0][i] = c[0][i] % 26;
      printf("%c ", (char)(c[0][i] + 65));
    }

    m = m - 1;
    flag = flag + n;
  }

  getch();
  return 0;
}
