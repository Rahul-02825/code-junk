#include <stdio.h>
#include <string.h>
int len(char s[])
{
    int i=0;
   while(s[i]!='\0')
   {
        i++;
   }
   return i;
}
void strrrev(char st[]) {
   int i,j;
   char ch;

   j =  len(st) - 1;
   i = 0;

   while(i < j) {
      ch = st[j];
      st[j] = st[i];
      st[i] = ch;
      i++;
      j--;
   }
}
int main()
{
  /*char string[100];//,temp[50],reverse[100];
   int i,j,n;
   gets(string);
   char temp[50],reverse[100];
   n=len(string);
   //printf("The lenght of the string is:%d",n);
   for(i=n-1;i>=0;--i)
   {
       for(j=0;i>=0 && string[i] !=' ';--i,++j)
       {
           temp[j]=string[i];
       }
       temp[j]='\0';
       strrrev(temp);
       strcat(reverse,temp);
       strcat(reverse," ");
   }*/

    char string[100]; //= "Taj Mahal is one of the seven wonders of the world";
   gets(string);
   char reverse[100] , temp[50];
   int i,j,n;

   n = len(string);

   for(i = n-1; i >= 0; --i) {

      for(j = 0; i >= 0 && string[i] != ' '; --i,++j)
      {
         temp[j] = string[i];
      }

      temp[j] = '\0';
      strrev(temp);
      strcat(reverse,temp);
      strcat(reverse," ");

   }
   printf("array is %s",reverse);
}
