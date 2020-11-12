#include <stdio.h>

int func(int n) {
     int x=1,k;
     if(n == 1) {
          return x;
     }
     for(k=1;k<n;k++) {
          x= x + func(k)*func(n-k);
     }
     return x;
}

int main() {
     int n;
     scanf("%d", &n);

     printf("%d\n", func(n));

     return 0;
}
