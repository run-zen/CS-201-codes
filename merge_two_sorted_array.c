#include <stdio.h>

int main ()
{
  int a[10], b[10],c[20], n, m, fsize,key;
  printf ("Enter the size of first array(max size-10):\n");
  scanf ("%d", &n);
  printf ("Enter the size of second array(max size-10):\n");
  scanf ("%d", &m);
  fsize = n + m;  //total size of combined array
  if (fsize > 20 || n>10 || m>10) {
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
// merging the arrays a and b into c
  for (int i=0;i<n;i++)
  {
    c[i]=a[i];
  }
  for(int i=n; i<fsize; i++)
  {
    c[i] =b[i-n];
  }
  //Sorting the merged array in ascending order
  for (int i=1;i< fsize; i++)
  {
    key = c[i];
    int j = i-1;
    while (j>=0 && c[j] > key)
    {
      c[j+1] = c[j];
      j--;
    }
    c[j+1] = key;
  }
  printf ("The sorted merged array is : \n");
  for (int i = 0; i < fsize; i++)
    {
      printf ("%d\t", c[i]);
    }

  return 0;
}
