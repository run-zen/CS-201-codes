#include <stdio.h>

int main()
{
     char str[21],substr[21];

     printf("\nEnter any string(maximum size 20) : ");
     gets(str);
     printf("\nEnter the sub-string to be extracted(max size 20) : ");
     gets(substr);

     int i = 0,len1 = 0,len2 = 0,flag = 1;
     int no_of_substr = 0;
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
     if (len1 >20 || len2 > 20)
     {
          printf("\nStrings entered is greater than the maximum size\n");
          return 0;
     }


     //comparing str2 to str1
     if (len1 == len2)
     {
          printf("\nThe sub-string is same as the original string\n");
          return 0;
     }
     else if(len1 < len2)
     {
          printf("\nSub-string cannot be larger than the original string\n");
          return 0;
     }
     else
     {
          int j=0,k=0;
          i = 0;
          while (str[i] != '\0')
          {
               flag = 0;
               if( str[i] == substr[0])
               {
                    k = i;
                    j = 0;
                    flag = 1;
                    while (substr[j] != '\0')
                    {
                         if(str[k] != substr[j])
                         {
                              flag = 0;
                              break;
                         }
                         j++;
                         k++;
                    }
                    if (flag == 1)
                    {
                         k = i;
                         while (str[k+len2] != '\0')
                         {
                              str[k] = str[k+len2];
                              k++;
                         }
                         str[k] = '\0';
                    }
               }
               if (str[i] == '\0')
               {
                    break;
               }
               i++;
               if (flag == 1)
                    i = i-1;

          }

          printf("\nString after extraction : ");
          puts(str);
     }

     return 0;
}
