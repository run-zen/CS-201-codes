#include <stdio.h>

int main() {
     int arr[5];
     int n=5;
     for (int i=0;i<5; i++) {
          scanf("%d", &arr[i]);
     }

     printf("\nThe sorted array is :\n");

     for (int i=0;i<n-1; i++) {
          int small = arr[i];
          int pos = i;
          for (int j=i+1; j<n; j++) {
               if (small > arr[j]) {
                    small = arr[j];
                    pos= j;
               }
          }
          int temp = arr[i];
          arr[i] = small;
          arr[pos] = temp;

          /* for observing the passes
          printf("\nPass %d : ", i+1);
          for (int i=0; i<n; i++) {
               printf("%d  ", arr[i]);
          }
          */
     }
     for (int i=0; i<n; i++) {
          printf("%d  ", arr[i]);
     }

     return 0;
}
