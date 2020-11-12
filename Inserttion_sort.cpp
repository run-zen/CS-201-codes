#include <iostream>

using namespace std;

int main()
{
     int n;
     printf("\nEnter the number of elements : ");
     scanf("%d",&n);
     int arr[n];
     for (int i=0; i<n; i++) 
     {
          scanf("%d",&arr[i]);
     }
     for (int i = 1; i<n; i++)
     {
          int key = arr[i];
          int j = i-1;
          while (j>=0 && arr[j] > key )
          {
               arr[j+1] = arr[j];
               j--;
          } 
          arr[j+1] = key;
     }
     printf("\nThe sorted elements is : \n");
     for (int i = 0; i<n; i++)
     {
          printf("%d  ", arr[i]);
     }

     return 0;
}
