#include <stdio.h>

int main ()
{
  int a[20], b[10], n, m, fsize;
  printf ("Enter the size of first array(max size-10):\n");
  scanf ("%d", &n);
  printf ("Enter the size of second array(max size-10):\n");
  scanf ("%d", &m);
  fsize = n + m;
  if (fsize > 20 || n>10 || m >10) {
      printf("Size exceeds maximum size of arrays.");
      return 0;
  }
  printf ("Enter the elements of first array:\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }

  printf ("Enter the elements of second array:\n");
  for (int i = 0; i < m; i++)
    {
      scanf ("%d", &b[i]);
    }

  for (int i = n; i < fsize; i++)
    {
      a[i] = b[i - n];
    }
  printf ("The merged array is : \n");
  for (int i = 0; i < fsize; i++)
    {
      printf ("%d\t", a[i]);
    }

  return 0;
}
