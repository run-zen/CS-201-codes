#include <stdio.h>

int main ()
{
  int a[10][10], b[10][10],sum[10][10],diff[10][10],trans_a[10][10],trans_b[10][10];
  int product[10][10];
  int row1,col1,row2,col2;
  printf("Maximum size of row and column must be less than equal to 10.\n");
  printf ("Enter the size of first array:\n");
  scanf ("%d %d", &row1,&col1);
  if (row1 >10 || col1 > 10)
  {
    printf("Size exceeds maximum size\n");
    return 0;
  }
  printf ("Enter the size of second array:\n");
  scanf ("%d %d", &row2,&col2);
  if (row2 >10 || col2 > 10)
  {
    printf("Size exceeds maximum size\n");
    return 0;
  }
  // getting first array elements
  printf("\nEnter the elements of first array (row-wise) :\n");
  for (int i=0;i<row1;i++)
  {
    for(int j=0; j< col1;j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  // getting second array elements
  printf("\nEnter the elements of second array (row-wise) :\n");
  for (int i=0;i<row2;i++)
  {
    for(int j=0; j< col2;j++)
    {
      scanf("%d", &b[i][j]);
    }
  }

  // transposing first array
  printf("\nThe transpose of the first array :\n");
  for (int i=0;i<row1;i++)
  {
    for(int j=0; j< col1;j++)
    {
      trans_a[j][i] = a[i][j];
    }
  }
  for (int i=0;i<col1;i++)
  {
    for(int j=0; j< row1;j++)
    {
      printf("%d  ", trans_a[i][j]);
    }
    printf("\n");
  }
  // transposing second array
  printf("\nThe transpose of the second array :\n");
  for (int i=0;i<row2;i++)
  {
    for(int j=0; j< col2;j++)
    {
      trans_b[j][i] = b[i][j];
    }
  }
  for (int i=0;i<col2;i++)
  {
    for(int j=0; j< row2;j++)
    {
      printf("%d  ", trans_b[i][j]);
    }
    printf("\n");
  }
  // find sum and difference of the arrays
  if (row1 != row2 || col1 != col2) {
    printf("Arrays cannot be added and subtracted.\n");
  }
  else
  {
    // printing sum array
    printf("The sum of the arrays is :\n");
    for (int i=0;i<row1;i++)
    {
      for(int j=0; j< col1;j++)
      {
        sum[i][j] = a[i][j] + b[i][j];
        diff[i][j] = a[i][j] - b[i][j];
        printf("%d  ",sum[i][j]);
      }
      printf("\n");
    }
    // printing the difference array
    printf("\nThe difference of the arrays is :\n");
    for (int i=0;i<row1;i++)
    {
      for(int j=0; j< col1;j++)
      {
        printf("%d  ", diff[i][j]);
      }
      printf("\n");
    }
  }

  // finding the product
  if (col1 != row2)
  {
    printf("\nArrays cannot be multiplied.\n");
  }
  else
  {
        int sum =0;
        for (int i=0;i <row1;i++)
        {
          for (int j = 0;j<col2;j++)
          {
            sum = 0;
            for (int k=0;k<col1; k++)
            {
              sum = sum + a[i][k]*b[k][j];
            }
            product[i][j] = sum;
          }
        }
        printf("\nThe product of the arrays is :\n");
        for (int i=0;i<row1;i++)
        {
          for(int j=0; j< col2;j++)
          {
            printf("%d  ", product[i][j]);
          }
          printf("\n");
        }
  }


  return 0;
}
