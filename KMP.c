#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int * calculate(char * pattern_str)
{
   int *lps = (int *)malloc(sizeof(int)*strlen(pattern_str));
   memset(lps, 0, sizeof(int)*strlen(pattern_str));

   int pattern_length = strlen(pattern_str);

   int j = 0;
   for (int i = 1; i < pattern_length; i++)
   {
      while (j > 0 && pattern_str[i] != pattern_str[j])
      {
         j = lps[j - 1];
      }
      if (pattern_str[i] == pattern_str[j])
      {
         j++;
         lps[i] = j;
      }
   }
   return lps;
}
void main()
{
   char target_str[1000]="ABCABAC";

   char pattern_str[1000]="ABA";

   int target_length = strlen(target_str);
   int pattern_length = strlen(pattern_str);

   int *lps = calculate(pattern_str);
   int j = 0;
   for (int i = 0; i < target_length; i++)
   {
      while (j > 0 && target_str[i] != pattern_str[j])
      {
         j = lps[j - 1];
      }
      if (pattern_str[j] == target_str[i])
      {
         if (j == pattern_length - 1)
         {
            printf("Found at %d\n",i-j);
            j = 0;
         }
         else
         {
            j++;
         }
      }
   }
}