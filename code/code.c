#include <stdio.h>
#include <string.h>
int main()
{
    int flag=0;
    int i,j,n,temp=0,len;
    char string[100];
    printf("Give the string:\n");
    gets(string);
    len=strlen(string);
    i=0;
    while(string[i]!='\0')
    {
        if(string[i]==' ')
        {
            flag=string[i];
            break;
        }
        i++;
    }
    for(j=flag;j<len/2;j++)
    {
        temp=string[j];
        string[j]=string[len-j-1];
        string[len-j-1]=temp;
    }
    for(k=len;k<len/2;len--)
    {
        temp=string[k];
        string[k]=string[len-k-1];
        string[len-k-1]=temp;
    }
    printf("%s",string);
}
