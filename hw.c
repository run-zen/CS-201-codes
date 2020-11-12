#include <stdio.h>

int main()
{
     char str[41],substr[21];
     int pos;

     printf("\nEnter any string(maximum size 20) : ");
     gets(str);
     printf("\nEnter the string to be inserted (max size 20) : ");
     gets(substr);
     printf("\nEnter the insertion position of string in the main string : ");
     scanf("%d", &pos);

     int i = 0,len1 = 0,len2 = 0;
     while (str[i] != '\0')
     {
          i++;
          len1++;
     }
     i = 0;
     while (substr[i] != '\0')
     {
          i++;
          len2++;
     }
     if (pos >len1)
     {
          printf("\nCannot be inserted outside the main string\n");
          return 0;
     }
     if (len1 >20 || len2 > 20)
     {
          printf("\nStrings entered is greater than the maximum size\n");
          return 0;
     }


     //inserting substr into str
     pos--;
     for (i = len1-1; i >= pos; i--)
     {
          str[i+len2] = str[i];
     }
     str[len1 + len2] = '\0';
     for (i = 0; i<len2; i++)
     {
          str[pos+i] = substr[i];
     }

     printf("\nString after insertion : ");
     puts(str);


     return 0;
}
