#include <stdio.h>

int main()
{
     char str1[41],str2[21];

     printf("\nEnter any string(maximum size 20) : ");
     gets(str1);
     printf("\nEnter another string to append to the previous string(max size 20) : ");
     gets(str2);

     int i = 0,len1 = 0,len2 = 0;
     while (str1[i] != '\0')
     {
          i++;
          len1++;
     }
     i = 0;
     while (str2[i] != '\0')
     {
          i++;
          len2++;
     }

     if (len1 > 20 || len2 > 20)
     {
          printf("\nStrings entered is greater than the maximum size\n");
          return 0;
     }

     //appending str2 to str1
     i=0;
     while (str2[i] != '\0')
     {
          str1[len1+i] = str2[i];
          i++;
     }
     str1[len1+len2] = '\0';
     //str2 is appended to str1

     printf("\nThe appended string is : ");
     puts(str1);

     return 0;
}
