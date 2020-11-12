#include <stdio.h>

int main()
{
     char str[101],substr[11],repstr[11];

     printf("\nEnter any string (maximum size 20) : ");
     gets(str);
     printf("\nEnter the pattern to be replaced (max size 10) : ");
     gets(substr);
     printf("\nEnter the pattern to be replaced with (max size 10) : ");
     gets(repstr);

     int i = 0,len1 = 0,len2 = 0,len3 = 0,flag = 1,pos = 0;
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
     i = 0;
     while (repstr[i] != '\0')
     {
          i++;
          len3++;
     }
     if (len1 >20 || len2 > 10 || len3 > 10)
     {
          printf("\nStrings entered is greater than the maximum size\n");
          return 0;
     }


     //replacing pattern substr with repstr in main string
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
                    pos = i;
                    len1 = len1 - len2;
                    for (j = len1-1; j >= pos; j--)
                    {
                         str[j+len3] = str[j];
                    }
                    str[len1 + len3] = '\0';
                    for (j = 0; j<len3; j++)
                    {
                         str[pos+j] = repstr[j];
                    }
                    len1 = len1 + len3;
               }
          }
          if (flag == 1)
               i = i+len3;
          else
               i++;

     }
     printf("\nString after replacement : ");
     puts(str);

     return 0;
}
